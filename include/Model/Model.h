#ifndef MCMODEL_MODEL_H_GUARD
#define MCMODEL_MODEL_H_GUARD

#include <unordered_map>
#include <map>
#include <cmath>
#include <vector>
#include <string>

#include "Util.h"
#include "NBT_Debug.h"

#include "rapidjson/document.h"

class ResourceManager;

namespace Model {
	struct Variant;

	class Model
	{
		public:
			Model();
			~Model();
			
			static Model *Create(const std::string &name);

			const std::vector<Variant *> &getVariants() { return variants_; }
			
			void dump();
			
		private:
			std::string name_;
			std::vector<Variant *> variants_;
			
			bool loadBlockstate(const std::string &name);
			bool loadVariant(const std::string &key, rapidjson::Value &v);
	};
}

#endif /* MCMODEL_MODEL_H_GUARD */
