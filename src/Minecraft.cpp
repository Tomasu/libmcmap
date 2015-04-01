#include "Minecraft.h"

//#define _XOPEN_SOURCE
#include <time.h>

#include <algorithm>

#include <unistd.h>
#include <sys/types.h>

#if  defined(__unix__)
#include <pwd.h>
#endif

#include "ioaccess/IOAccess.h"

#include "NBT_Debug.h"
#include "rapidjson/error/en.h"
#include "rapidjson/document.h"

namespace
{
	// if(!strptime(releaseDateValue.GetString(), "%Y-%m-%dT%T%z", &tm))
	void parseTime(const char *time_str, tm &time_data)
	{
		std::string temp(time_str);
		using std::stoi;
		NBT_Debug("Parse time! \"%s\"", time_str);
		NBT_Debug("Cut example: %s", temp.substr(0, 4).data());
		time_data.tm_year = stoi(temp.substr(0, 4)) - 1900;
		time_data.tm_mon = stoi(temp.substr(5, 2)) - 1;
		time_data.tm_mday = stoi(temp.substr(8, 2));
		time_data.tm_hour = stoi(temp.substr(11, 2));
		time_data.tm_min = stoi(temp.substr(14, 2));
		time_data.tm_sec = stoi(temp.substr(17, 2));
		time_data.tm_isdst = 0;
		NBT_Debug("mktime output: %u", mktime(&time_data));
		NBT_Debug("Year: %d, Mon: %d, MDay: %d, Hour: %d, Min: %d, Sec: %d, is_dst: %d", time_data.tm_year, time_data.tm_mon, time_data.tm_mday, time_data.tm_hour, time_data.tm_min, time_data.tm_sec, time_data.tm_isdst);
	}
}

Minecraft::Minecraft()
{ }

bool Minecraft::init(const std::string& path)
{
	std::string loc_path = path;

	if(!loc_path.length())
		loc_path = findBaseDir();

	if(!loc_path.length())
		return false;

	IOAccess::StatInfo si;
	if(!IOAccess::Stat(loc_path, &si))
	{
		NBT_Debug("failed to stat %s: %s", loc_path.c_str(), strerror(IOAccess::Errno()));
		return false;
	}

	if(!si.isDir())
	{
		NBT_Debug("%s is not a directory", loc_path.c_str());
		return false;
	}

	if(!findVersions(loc_path))
	{
		NBT_Debug("failed to find versions for %s", loc_path.c_str());
		return false;
	}

	base_path = loc_path;

	return true;
}

Minecraft *Minecraft::Create(const std::string& path, const std::string &saves_path)
{
	Minecraft *mc = new Minecraft();

	if(!mc->init(path))
	{
		delete mc;
		return nullptr;
	}

	mc->findSaves(saves_path.length() ? saves_path : path);

	return mc;
}


Minecraft::~Minecraft()
{
	NBT_Debug("We're done!");
}

bool Minecraft::autoSelectVersion()
{
	VersionMap::iterator it;
	MinecraftVersion loc_selected_version;
	std::string loc_selected_jarpath;

	it = version_map_.begin();

	loc_selected_version = it->first;
	loc_selected_jarpath = it->second;

	while(it != version_map_.end())
	{
		MinecraftVersion cur_ver = it->first;
		std::string jar_path = it->second;

		NBT_Debug("test version %s: %s", loc_selected_version.str().c_str(), jar_path.c_str());

		// do not auto select snapshots
		if(cur_ver.isSnapshot())
		{
			it++;
			continue;
		}

		it++;

		if(cur_ver > loc_selected_version)
		{
			loc_selected_version = cur_ver;
			loc_selected_jarpath = jar_path;
		}
	}

	return selectVersion(loc_selected_version, loc_selected_jarpath);
}

bool Minecraft::selectVersion(const std::string& sver)
{
	for(auto &mcv: version_map_)
	{
		if(mcv.first.str() == sver)
		{
			NBT_Debug("selected version %s: %s", mcv.first.str().c_str(), mcv.second.c_str());
			selected_version = mcv.first;
			selected_jar = mcv.second;
			return true;
		}
	}

	return false;
}

bool Minecraft::selectVersion(const MinecraftVersion& mcv)
{
	// skip invalid versions...
	if(!mcv.isValid())
	{
		NBT_Debug("version is invalid");
		return false;
	}

	VersionMap::iterator it = version_map_.find(mcv);
	if(it == version_map_.end())
	{
		NBT_Debug("version not found in map");
		return false;
	}

	std::string &jar_path = it->second;

	return selectVersion(mcv, jar_path);
}

bool Minecraft::selectVersion(const MinecraftVersion& mcv, const std::string &jar_path)
{
	IOAccess::StatInfo si;
	if(!IOAccess::Stat(jar_path, &si))
	{
		NBT_Debug("failed to stat %s", jar_path.c_str());
		return false;
	}

	if(!si.isFile())
	{
		NBT_Debug("%s is not a file", jar_path.c_str());
		return false;
	}

	NBT_Debug("selected version %s: %s", mcv.str().c_str(), jar_path.c_str());

	selected_version = mcv;
	selected_jar = jar_path;

	return true;
}


bool Minecraft::findVersions(const std::string &base)
{
	std::string jar_path = base;
	std::string versions_path = jar_path + "/versions";

	if(!IOAccess::Exists(versions_path))
	{
		NBT_Debug("%s does not exist :(", versions_path.c_str());
		return false;
	}

	IOAccess::Directory *dir = IOAccess::OpenDirectory(versions_path);
	if(!dir)
		return false;

	std::string entry_name;
	while(dir->read(&entry_name, false))
	{
		std::string entry_path = versions_path + std::string("/") + entry_name;

		NBT_Debug("read: %s", entry_path.c_str());

		time_t releaseTime = 0;
		struct tm tm;
		rapidjson::Value releaseDateValue;
		rapidjson::Value releaseTypeValue;
		rapidjson::Value releaseIDValue;

		rapidjson::Document *version_json = nullptr;

		IOAccess::StatInfo si;
		if(!IOAccess::Stat(entry_path, &si))
		{
			NBT_Debug("failed to stat %s", entry_path.c_str());
			continue;
		}

		// ignore everything but listable directory entries
		if(!si.isDir() || !si.isExecutable())
		{
			NBT_Debug("%s not a directory (%i) or not executable (%i)", entry_path.c_str(), si.isDir(), si.isExecutable());
			continue;
		}

		std::string json_path = versions_path + std::string("/") +
			entry_name + std::string("/") + entry_name + ".json";

		version_json = LoadJson(json_path);
		if(!version_json)
			goto free_loop_data;

		releaseDateValue = (*version_json)["releaseTime"];
		releaseTypeValue = (*version_json)["type"];
		releaseIDValue = (*version_json)["id"];

		// NOTE: Possibly remove Poco
		/*
		#if defined(_WIN32) || defined(_WIN64)
		try
		{
			using std::string;
			int tzd = 0;
			Poco::DateTime date = Poco::DateTimeParser::parse(string("%Y-%m-%dT%T%z"),
				string(releaseDateValue.GetString()), tzd);
			time_t med = date.timestamp().epochTime();
			gmtime_r(&med, &tm);
		}
		catch (Poco::SyntaxException &e)
		{
			NBT_Debug("failed to parse releaseTime: %s", releaseDateValue.GetString());
			goto free_loop_data;
		}
		#else
		if(!strptime(releaseDateValue.GetString(), "%Y-%m-%dT%T%z", &tm))
		{
			NBT_Debug("failed to parse releaseTime: %s", releaseDateValue.GetString());
			goto free_loop_data;
		}
		#endif
		*/
		parseTime(releaseDateValue.GetString(), tm);

		releaseTime = mktime(&tm);
		NBT_Debug("Parsed timestamp: %u", releaseTime);

		{
			MinecraftVersion ver = MinecraftVersion(releaseIDValue.GetString(), releaseTime, strcmp(releaseTypeValue.GetString(), "snapshot")==0);
			std::string jp = versions_path + std::string("/") +
				entry_name + std::string("/") + entry_name + ".jar";

			NBT_Debug("found ver: %s @ %s", ver.str().c_str(), jp.c_str());
			version_map_.emplace(ver, jp);
		}

		free_loop_data:

		if(version_json)
			delete version_json;
	}

	if(version_map_.size() < 1)
	{
		NBT_Debug("failed to find any mc versions?");
		goto err;
	}

	delete dir;
	
	//std::sort(version_map_.begin(), version_map_.end());
	return true;

err:
	delete dir;
	return false;

}

std::string Minecraft::findBaseDir()
{
	std::string root_dir;
	const char *data_root = nullptr;

#if defined(_WIN32) || defined(_WIN64)
	data_root = getenv("APPDATA");
#else
	struct passwd *pw = getpwuid(getuid());
	if(!pw)
		data_root = getenv("HOME");
	else
		data_root = pw->pw_dir;
#endif

	root_dir = data_root;
	root_dir += "/";

#ifdef __APPLE__
	root_dir += "Library/Application Support/minecraft";
#else
	root_dir += ".minecraft";
#endif

	return root_dir;
}

bool Minecraft::findSaves(const std::string &base)
{
	NBT_Debug("findSaves begin");
	std::string saves_base = base;
	if(!saves_base.length())
		saves_base = base_path;
	
	IOAccess::StatInfo si;
	if(!IOAccess::Stat(saves_base, &si))
	{
		NBT_Debug("failed to stat %s: %s", saves_base.c_str(), strerror(IOAccess::Errno()));
		return false;
	}

	if(!si.isDir())
	{
		NBT_Debug("%s is not a directory", saves_base.c_str());
		return false;
	}

	// check base/saves before base for level.dat because we may have a spurious level.dat in "saves_base".
	std::string saves_path = saves_base + "/saves";

	if(isSave(saves_path))
	{
		NBT_Debug("isSave: %s", saves_path.c_str());
		saves_.push_back(saves_path);
		return true;
	}

	if(isSave(saves_base))
	{
		NBT_Debug("isSave: %s", saves_base.c_str());
		saves_.push_back(saves_base);
		return true;
	}
	
	if(IOAccess::Stat(saves_path, &si) && si.isDir())
		saves_base = saves_path;

	IOAccess::Directory *dir = IOAccess::OpenDirectory(saves_base);
	if(!dir)
	{
		NBT_Debug("failed to open directory %s: %s", saves_base.c_str(), strerror(IOAccess::Errno()));
		return false;
	}

	std::string ent;
	while(dir->read(&ent, true))
	{
		if(isSave(ent))
		{
			NBT_Debug("isSave: %s", ent.c_str());
			saves_.push_back(ent);
		}
	}

	delete dir;
	return saves_.size() != 0;
}

bool Minecraft::isSave(const std::string &path)
{
	IOAccess::StatInfo si;
	if(!IOAccess::Stat(path, &si))
		return false;

	// ignore everything but listable directory entries
	if(!si.isDir() || !si.isExecutable())
		return false;

	std::string level_dat_path = path + "/level.dat";

	// if level.dat does not exist or is not readable, skip
	if(!IOAccess::Stat(level_dat_path, &si))
		return false;

	if(!si.isFile() || !si.isReadable())
		return false;
	
	NBT_Debug("IS SAVE: %s", path.c_str());

	return true;
}

rapidjson::Document *Minecraft::LoadJson(const std::string &p)
{
	std::string path = p;
	rapidjson::Document *doc = nullptr;
	char *buffer = nullptr;

	//NBT_Debug("attempting to fetch %s.json", path.c_str());

	// cache ftw
	//auto it = jsonDocCache_.find(path);
	//if(it != jsonDocCache_.end() && it->second)
	//	return it->second;

	// path += ".json";

	IOAccess::File *fh = IOAccess::OpenFile(path, "r");
	if(!fh)
	{
		NBT_Debug("failed to open json (%s): %s", path.c_str(), strerror(IOAccess::Errno()));
		return nullptr;
	}

	IOAccess::StatInfo si;
	if(!IOAccess::Stat(path, &si))
	{
		NBT_Debug("failed to stat %s: %s", strerror(IOAccess::Errno()));
		goto getJson_err;
	}

	if(si.size < 1)
	{
		//NBT_Debug("json file is empty?");
		goto getJson_err;
	}

	buffer = (char *)malloc(si.size + 1);
	if(!buffer)
		goto getJson_err;

	memset(buffer, 0, si.size+1);

	if(fh->read(buffer, si.size) != (size_t)si.size)
	{
		//NBT_Error("failed to read %i bytes from file", fsize);
		goto getJson_err;
	}

	doc = new rapidjson::Document;

	doc->Parse(buffer);

	if(doc->HasParseError())
	{
		const char *errstr = rapidjson::GetParseError_En(doc->GetParseError());
		NBT_Error("error parsing json: %s", errstr);

		size_t err_off = doc->GetErrorOffset();
		char err_buff[1024];
		memset(err_buff, 0, sizeof(err_buff));

		const char *eoline = strchr(buffer+err_off, '\n');
		if(!eoline)
			eoline = buffer+si.size;

		size_t err_minsz = std::min<std::size_t>(sizeof(err_buff)-1, eoline-buffer-1);
		memcpy(err_buff, buffer+err_off, err_minsz);

		NBT_Error("at[%i]: %s", err_off, err_buff);

		goto getJson_err;
	}

	//jsonDocCache_.emplace(path, doc);

	//NBT_Debug("got json!");
	//return jsonDocCache_[path];

	delete fh;
	free(buffer);
	return doc;

getJson_err:
	if(doc)
		delete doc;

	if(buffer)
		free(buffer);

	if(fh)
		delete fh;

	return nullptr;
}
