#include "Model/Model.h"
#include "Model/Variant.h"

#ifdef Bool
#undef Bool
#endif

#include "Minecraft.h"
#include "rapidjson/document.h"
#include "NBT_Debug.h"

// assuming [ x, z, y ]

// element from hopper:
// "from": [ 0, 11, 0 ],
// "to": [ 2, 16, 16 ],

// or from cube:
// "from": [ 0, 0, 0 ],
// "to": [ 16, 16, 16 ],
				
// how to turn the above into verticies...
/* first need to get the individual faces...
 * 
 * [ from.x, from.z, from.y ], [ from.x, from.z, to.y ], 
 * 
 * 
 */

namespace Model {

	Model::Model()
	{ }

	Model::~Model()
	{
		for(auto variant: variants_)
		{
			delete variant;
		}
	}

	bool Model::loadVariant(const std::string &key, rapidjson::Value &v)
	{
		Variant *variant = new Variant;
		
		NBT_Debug("load Variant: %s", key.c_str());
		if(!variant->load(key, v))
			return false;
		
		variants_.push_back(variant);
		
		return true;
	}

	bool Model::loadBlockstate(const std::string &name)
	{
		rapidjson::Document *doc = Minecraft::LoadJson(std::string("assets/minecraft/blockstates/") + name + ".json");
		if(!doc)
			return false;
		
		NBT_Debug("load Blockstate: %s", name.c_str());
		
		if(doc->HasParseError())
		{
			NBT_Debug("json parse error");
			delete doc;
			return false;
		}
		
		rapidjson::Value &variants = (*doc)["variants"];
		if(!variants.MemberCount())
		{
			NBT_Debug("no variants?");
			delete doc;
			return false;
		}
		
		for(auto it = variants.MemberBegin(); it != variants.MemberEnd(); it++)
		{
			const char *member_key = it->name.GetString();
			rapidjson::Value &member_value = it->value;
			
			// value can be an array or object
			
			if(member_value.IsObject())
			{
				if(!loadVariant(member_key, member_value))
					continue;
			}
			else if(member_value.IsArray())
			{
				int vid = 0;
				for(auto it = member_value.Begin(); it != member_value.End(); it++)
				{
					char buff[101];
					snprintf(buff, 100, "%i", vid);
					vid++;
					if(!loadVariant(buff, *it))
						continue;
				}
			}
			else { NBT_Debug("unknown variant type?"); }
		}
		
		name_ = name;
		
		delete doc;
		return true;
	}



	Model *Model::Create(const std::string &name)
	{
		Model *model = new Model;
		
		if(!model->loadBlockstate(name))
		{
			delete model;
			return nullptr;
		}
		
		return model;
	}

	void Model::dump()
	{
		NBT_Debug("dump model: %s", name_.c_str());
		for(auto it = variants_.begin(); it != variants_.end(); it++)
		{
			(*it)->dump();
		}
	}


}
