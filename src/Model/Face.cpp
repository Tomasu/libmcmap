#include "Model/Face.h"
#include "Model/Variant.h"

#include "NBT_Debug.h"
#include "Util.h"

namespace Model {
	
bool Face::load(Variant *variant, FaceDirection dir, rapidjson::Value &v)
{
	if(v.IsNull() || !v.IsObject())
		return false;
	
	direction = dir;
	rotation = 0.0;
	
	uv.f1 = 0.0;
	uv.f2 = 0.0;
	uv.f3 = 1.0;
	uv.f4 = 1.0;
		
	// Atlas *atlas = rm->getAtlas();
	
	cull = CULL_NONE;
	
	tintindex = 0;
	
	for(auto it = v.MemberBegin(); it != v.MemberEnd(); it++)
	{
		if(it->name == "uv")
		{
			if(!uv.load(it->value))
				return false;
		}
		else if(it->name == "texture")
		{
			const char *tex_key = it->value.GetString();
			const char *tex_name = tex_key[0] != '#' ? tex_key : variant->lookupTextureKey(&(tex_key[1])).c_str();
			
			//NBT_Debug("face tex: %s -> %s", tex_key, tex_name);
			texname = std::string(tex_name);
		}
		else if(it->name == "cullface")
		{
			rapidjson::Value &v = it->value;
			
			if(v == "up")
				cull = CULL_UP;
			else if(v == "down")
				cull = CULL_DOWN;
			else if(v == "north")
				cull = CULL_NORTH;
			else if(v == "east")
				cull = CULL_EAST;
			else if(v == "south")
				cull = CULL_SOUTH;
			else if(v == "west")
				cull = CULL_WEST;
			else
				cull = CULL_NONE;
		}
		else if(it->name == "tintindex")
		{
			tintindex = it->value.GetInt();
		}
		else if(it->name == "rotation")
		{
			rotation = -it->value.GetDouble();
		}
	}
	
	if(uv.f1 == 0.0 && uv.f2 == 0.0 && uv.f3 == 0.0 && uv.f4 == 0.0)
	{
		uv.f1 = 0.0;
		uv.f2 = 0.0;
		uv.f3 = 1.0;
		uv.f4 = 1.0;
	}
	
	// FIXME: gotta do something about this shit
	/*
	if(rotation != 0.0)
	{
		ALLEGRO_TRANSFORM rot;
		al_identity_transform(&rot);
		al_translate_transform(&rot, -0.5, -0.5);
		al_rotate_transform(&rot, DEG_TO_RAD(rotation));
		al_translate_transform(&rot, 0.5, 0.5);
		
		//al_transform_coordinates(&rot, &uv.f1, &uv.f2);
		//al_transform_coordinates(&rot, &uv.f3, &uv.f4);
	}
	
	tex_res = rm->getBitmap(texname);
	if(tex_res != Resource::INVALID_ID)
	{
		Atlas::Item item;
		if(rm->getAtlasItem(tex_res, &item))
		{
			float xfact = atlas->xfact();
			float yfact = atlas->yfact();
			
			uv.f1 = uv.f1 * xfact + item.x * xfact;
			uv.f2 = uv.f2 * yfact + item.y * yfact;
			
			uv.f3 = uv.f3 * xfact + item.x * xfact;
			uv.f4 = uv.f4 * yfact + item.y * yfact;
			
			tex_page = item.sheet + 1;
		}
	}
	
	if(uv.f1 == 0.0 && uv.f2 == 0.0 && uv.f3 == 0.0 && uv.f4 == 0.0)
	{
		uv.f1 = 0.0;
		uv.f2 = 0.0;
		uv.f3 = 1.0 * atlas->xfact();
		uv.f4 = 1.0 * atlas->yfact();
	}
	*/
	
	return true;
}

}
