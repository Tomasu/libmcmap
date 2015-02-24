#include "Model/Variant.h"
#include "Model/Element.h"

#include "NBT_Debug.h"
#include "Util.h"

#include "Minecraft.h"

namespace Model {
	
	bool Variant::load(const std::string &k, rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsObject())
		{
			NBT_Debug("Variant is not valid?");
			return false;
		}
		
		x = 0.0;
		y = 0.0;
		key = k;
		
		size_t last_pos = -1, pos = 0;
		std::string bstate_key;
		
		while((pos = key.find_first_of(",=", last_pos+1)) != std::string::npos)
		{
			std::string part = key.substr(last_pos+1, pos - last_pos - 1 );
			
			if(key[pos] == '=')
			{
				bstate_key = part;
			}
			else if(key[pos] == ',')
			{
				state_map_.emplace(bstate_key, part);
				NBT_Debug("bstate: %s=%s", bstate_key.c_str(), part.c_str());
				bstate_key.erase();
			}
			
			last_pos = pos;
		}
		
		if(!bstate_key.empty())
		{
			std::string part = key.substr(last_pos+1);
			NBT_Debug("bstate: %s=%s", bstate_key.c_str(), part.c_str());
			state_map_.emplace(bstate_key, part);
		}
		
		for(auto it = v.MemberBegin(); it != v.MemberEnd(); it++)
		{
			if(it->name == "model")
				model = it->value.GetString();
			else if(it->name == "x")
				x = it->value.GetInt();
			else if(it->name == "y")
				y = it->value.GetInt();
			else if(it->name == "uvlock")
				uvlock = it->value.GetBool();
		}
		
		if(!model.length())
		{
			NBT_Debug("variant is missing name property");
			return false;
		}
		
		model = "block/" + model;
		
		if(!loadModel(model))
		{
			NBT_Debug("failed to load variant model?");
			return false;
		}
		
		rotate();
		
		return true;
	}
	
	std::string Variant::lookupTextureKey(const std::string &s)
	{
		return texture_map_[s];
	}

	bool Variant::loadElements(rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsArray())
		{
			NBT_Debug("elements is not an array?");
			return false;
		}
		
		for(auto it = v.Begin(); it != v.End(); it++)
		{
			Element *element = new Element;
			if(!element->load(this, *it))
				return false;
			
			elements_.emplace(elements_.end(), element);
		}
		
		return true;
	}

	bool Variant::loadTextures(rapidjson::Value &v)
	{
		if(v.IsNull() || !v.IsObject())
			return false;
		
		for(auto it = v.MemberBegin(); it != v.MemberEnd(); it++)
		{
			const char *tex_key = it->name.GetString();
			const char *val_name = it->value.GetString();
			
			const char *tex_name = val_name[0] != '#' ? val_name : lookupTextureKey(&(val_name[1])).c_str();
			
			texture_map_.emplace(tex_key, tex_name);
		}
		
		return true;
	}

	bool Variant::loadModel(const std::string &name)
	{
		rapidjson::Document *doc = Minecraft::LoadJson(std::string("assets/minecraft/models/block/") + name + ".json");
		if(!doc)
		{
			NBT_Debug("failed to get model json: %s", name.c_str());
			return false;
		}
		
		NBT_Debug("load Model: %s", name.c_str());
		
		if(doc->HasParseError())
		{
			NBT_Debug("json parse error?");
			return false;
		}
		
		const char *parent_name = nullptr;
		
		for(auto v = doc->MemberBegin(); v != doc->MemberEnd(); v++)
		{
			//NBT_Debug("member: %s:%i", v->name.GetString(), v->value.GetType());
			if(v->name == "elements")
			{
				if(!loadElements(v->value))
				{
					NBT_Debug("failed to load elements :(");
					return false;
				}
			}
			else if(v->name == "textures")
			{
				if(!loadTextures(v->value))
				{
					NBT_Debug("failed to load textures :(");
					return false;
				}
			}
			else if(v->name == "parent")
			{
				//NBT_Debug("parent: %s", v->value.GetString());
				parent_name = v->value.GetString();
			}
		}

		// odly, we need to handle parent after the main content.
		//  references are made from parent resources to textures defined in child resources.
		if(parent_name)
		{
			//NBT_Debug("load parent %s", parent_name);
			if(!loadModel(parent_name))
			{
				NBT_Debug("failed to load parent %s", parent_name);
				return false;
			}
			
		}
		
		return true;
	}

	void Variant::rotate()
	{
		// TODO: needs to not use allegro :( or be moved somehow
		/*
		if(x == 0.0 && y == 0.0)
			return;
		
		ALLEGRO_TRANSFORM rot;
		al_identity_transform(&rot);
		al_translate_transform_3d(&rot, -0.5, -0.5, -0.5);
		
		if(x != 0.0)
		{
		//	al_translate_transform_3d(&xrot, -1.0, -1.0, -1.0);
			al_rotate_transform_3d(&rot, 1, 0, 0, x * M_PI / 180.0);
			//al_translate_transform_3d(&xrot, -1.0, 0.0, 0.0);
		}
		
		if(y != 0.0)
		{
			//al_translate_transform_3d(&yrot, 0.0, 1.0, 0.0);
			al_rotate_transform_3d(&rot, 0, 1, 0, y * M_PI / 180.0);
			//al_translate_transform_3d(&yrot, 0.0, -1.0, 0.0);
		}
		
		//al_compose_transform(&xrot, &yrot);
		al_translate_transform_3d(&rot, 0.5, 0.5, 0.5);
		
		for(auto &elem: elements_)
		{
			for(uint32_t i = 0; i < elem->vertex_count; i++)
			{
				CUSTOM_VERTEX &v = elem->vertices[i];
				al_transform_coordinates_3d(&rot, &(v.pos.f1), &(v.pos.f2), &(v.pos.f3));
			}
		}
		*/
	}
	
	void Variant::dump()
	{
		NBT_Debug("variant: %s::%s", model.c_str(), key.c_str());
		NBT_Debug("textures:");
		for(auto it: texture_map_)
		{
			NBT_Debug("%s => %s", it.first.c_str(), it.second.c_str());
		}
		
		NBT_Debug("elements:");
		for(auto &element: elements_)
		{
			NBT_Debug("from: [%f,%f,%f] to: [%f,%f,%f]", element->from.f1, element->from.f2, element->from.f3, element->to.f1, element->to.f2, element->to.f3);
			
			for(uint32_t i = 0; i < Face::MAX_FACES; i++)
			{
				Face &face = element->faces[i];
				
				NBT_Debug("face[%i]: dir:%i uv:[%f,%f,%f,%f] texture:[%s] cull:[%i] tintindex:[%i]",
							i, face.direction, face.uv.f1, face.uv.f2, face.uv.f3, face.uv.f4, face.texname.c_str(), face.cull, face.tintindex);
			}
		}
	}
}
