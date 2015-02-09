#include "Minecraft.h"

#include <ioaccess/IOAccess.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

Minecraft::Minecraft(const std::string &path)
{
	
}

Minecraft::~Minecraft()
{
	
}

bool Minecraft::autoSelectVersion()
{
	VersionMap::reverse_iterator it;
	MinecraftVersion selected_version;
	
	it = version_map_.rbegin();
	selected_version = *it;
	
	while(it != version_map.rend())
	{
		selected_version = it->first;
		std::string jar_path = it->second;
		
		NBT_Debug("test version %s: %s", selected_version.str().c_str(), jar_path.c_str());
		
		// skip snapshots.
		if(it->isSnapshot())
		{
			it++;
			continue;
		}
		
		it++;
		
		// skip invalid versions...
		if(!selected_version.isValid())
		{
			NBT_Debug("selected_version is invalid");
			break;
		}
		
		StatInfo si;
		if(!IOAccess::Stat(ver_path, &si))
		{
			NBT_Debug("failed to stat %s", ver_path.c_str());
			continue;
		}
		
		if(!si.isFile())
		{
			NBT_Debug("%s is not a file", ver_path.c_str());
			continue;
		}
		
		NBT_Debug("selected version %s: %s", selected_version.str().c_str(), jar_path.c_str());
	
		return ver_path;
	}
}

std::string Minecraft::locateJar()
{
	std::string jar_path = base_path;
	std::string versions_path = jar_path + "/versions";
	
	if(!IOAccess::Exists(versions_path))
	{
		// don't really need this, we really only support minecrafts
		// with the versions folder... but what the heck.
		
		jar_path += "/minecraft.jar";

		if(IOAccess::Exists(jar_path))
			return jar_path;
		else
			return nullptr;
	}
	
	Directory *dir = IOAccess::OpenDirectory(versions_dir);
	if(!dir)
		return nullptr;
	
	std::string entry_name;
	do
	{
		entry_name = dir->read();
		if(!entry_name.length())
			break;
		
		std::string entry_path = versions_dir + std::string("/") + entry_name;
		
		time_t releaseTime = 0;
		struct tm tm;
		rapidjson::Value releaseDateValue;
		rapidjson::Value releaseTypeValue;
		rapidjson::Value releaseIDValue;
		
		rapidjson::Document *version_json = nullptr;
		
		StatInfo si;
		if(!IOAccess::Stat(entry_path, &si))
			continue;
		
		// ignore everything but listable directory entries
		if(!si.isDirectory() || !si.isExecutable())
			continue;
		
		std::string json_path = versions_path + std::string("/") +
			entry_name + std::string("/") + entry_name + ".json";
		
		version_json = getJson(json_path);
		if(!version_json)
			goto free_loop_data;
		
		releaseDateValue = (*version_json)["releaseTime"];
		releaseTypeValue = (*version_json)["type"];
		releaseIDValue = (*version_json)["id"];
		
		if(!strptime(releaseDateValue.GetString(), "%Y-%m-%dT%T%z", &tm))
		{
			NBT_Debug("failed to parse releaseTime: %s", releaseDateValue.GetString());
			goto free_loop_data;
		}
		
		releaseTime = mktime(&tm);
		
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
	while(1);
	
	delete versions_dir;
	
	if(version_map.size() < 1)
	{
		NBT_Debug("failed to find any mc versions?");
		goto err;
	}
	
	std::sort(version_map.begin(), version_map.end());

	err:
	
	return nullptr;
}

std::string Minecraft::locateData()
{
	std::string root_dir;
	const char *data_root = nullptr;
	
#ifdef _WIN32
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
