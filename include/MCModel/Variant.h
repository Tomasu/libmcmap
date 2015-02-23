#ifndef MCMODEL_VARIANT_H_GUARD
#define MCMODEL_VARIANT_H_GUARD

#include <map>
#include <vector>

#include "rapidjson/document.h"

class ResourceManager;

namespace MCModel {

	struct Element;

	struct Variant
	{
		public:
			std::string key;
			std::string model;
			int x, y;
			bool uvlock;
			bool ambientocclusion;
			
			std::map<std::string, std::string> texture_map_;
			std::vector<Element *> elements_;
			std::map<std::string, std::string> state_map_;
			
			bool load(const std::string &k, rapidjson::Value &v, ResourceManager *rm);
			
			bool loadModel(const std::string &name, ResourceManager *rm);
			bool loadElements(rapidjson::Value &v, ResourceManager *rm);
			bool loadTextures(rapidjson::Value &v);
			
			std::string lookupTextureKey(const std::string &s);

			void dump();
		
		private:
			void rotate();
	};

}

#endif /* MCMODEL_VARIANT_H_GUARD */
