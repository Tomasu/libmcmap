#ifndef MINECRAFT_H_GUARD
#define MINECRAFT_H_GUARD

class MinecraftVersion
{
	public:
		MinecraftVersion() : str_(), time_(0), snapshot_(true) { }
		
		MinecraftVersion(const std::string &str, time_t releaseTime, bool snapshot = false) : str_(str), time_(releaseTime), snapshot_(snapshot) { }
		~MinecraftVersion() { }
		
		bool operator==(const MinecraftVersion &in)
		{
			return (time_ == in.time_);
		}
		
		bool operator<(const MinecraftVersion &in)
		{
			// short circuit on type, snap, alpha, beta, release, etc
			return (time_ < in.time_);
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
		Minecraft(const std::string &path = "");
		~Minecraft();
		
		bool selectVersion(const MinecraftVersion &mcv);
		bool autoSelectVersion();
		
	private:
		std::string base_path;
		std::string selected_vers
		typedef std::map< MinecraftVersion, std::string > VersionMap;
		VersionMap version_map_;
		
		std::string locateData();
		std::string locateJar();
};



#endif /* MINECRAFT_H_GUARD */
