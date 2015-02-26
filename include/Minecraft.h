#ifndef MINECRAFT_H_GUARD
#define MINECRAFT_H_GUARD

#include <string>
#include <time.h>
#include <map>
#include <vector>

#include "rapidjson/document.h"

class MinecraftVersion
{
	public:
		MinecraftVersion() : str_(), time_(0), snapshot_(true) { }
		
		MinecraftVersion(const std::string &str, time_t releaseTime, bool snapshot = false) : str_(str), time_(releaseTime), snapshot_(snapshot) { }
		~MinecraftVersion() { }
		
		bool operator==(const MinecraftVersion &in) const
		{
			return (time_ == in.time_);
		}
		
		bool operator<(const MinecraftVersion &in) const
		{
			// short circuit on type, snap, alpha, beta, release, etc
			return (time_ < in.time_);
		}
		
		bool operator>(const MinecraftVersion &in) const
		{
			return (time_ > in.time_);
		}
		
		MinecraftVersion &operator=(const MinecraftVersion &rhs)
		{
			str_ = rhs.str_;
			time_ = rhs.time_;
			snapshot_ = rhs.snapshot_;
			
			return *this;
		}
		
		bool isValid() const { return time_ != 0; }
		bool isSnapshot() const { return snapshot_; }
		
		const std::string &str() const { return str_; }
		
	private:
		std::string str_;
		time_t time_;
		bool snapshot_;
};

class Minecraft
{
	public:
		typedef std::map< MinecraftVersion, std::string > VersionMap;
		typedef std::vector< std::string > SaveVector;
		
		Minecraft();
		~Minecraft();
		
		bool init(const std::string &path = "");
		static Minecraft *Create(const std::string& path, const std::string& saves_path = "");
		
		bool selectVersion(const std::string &sver);
		bool selectVersion(const MinecraftVersion &mcv);
		bool autoSelectVersion();
		
		const VersionMap &versionMap() const { return version_map_; }
		const MinecraftVersion &selectedVersion() const { return selected_version; }
		const std::string &selectedJar() const { return selected_jar; }
		
		bool findSaves(const std::string &base);
		
		const SaveVector &saves() const { return saves_; }
		
		static rapidjson::Document *LoadJson(const std::string &path);
		
	private:
		std::string base_path;
		MinecraftVersion selected_version;
		std::string selected_jar;
		
		VersionMap version_map_;
		SaveVector saves_;
		
		std::string findBaseDir();
		bool findVersions(const std::string &base);
		bool isSave(const std::string &path);
		
		bool selectVersion(const MinecraftVersion &mcv, const std::string &jar_path);
};



#endif /* MINECRAFT_H_GUARD */
