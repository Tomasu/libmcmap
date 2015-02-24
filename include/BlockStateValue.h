#ifndef BLOCK_STATE_VALUE_H_GUARD
#define BLOCK_STATE_VALUE_H_GUARD

#include "BlockStateValueConvert.h"

template <int TypeID>
class BlockStateValueMapType;

class BlockStateValue
{
	public:
		static const BlockStateValue NullValue;
		
		enum Type { TYPE_NONE = 0, TYPE_INT, TYPE_FLOAT, TYPE_STRING };
		
		BlockStateValue() : type(TYPE_NONE) { }
		BlockStateValue(int32_t iv) : type(TYPE_INT) { data.iv = iv; }
		BlockStateValue(float fv) : type(TYPE_FLOAT) { data.fv = fv; }
		BlockStateValue(const std::string &sv) : type(TYPE_STRING) { data.sv = sv; }
		
		BlockStateValue(const BlockStateValue &d) : type(d.type), data(d.data) { }
		
		~BlockStateValue()
		{ }
		
		BlockStateValue &operator=(const BlockStateValue &d)
		{
			type = d.type;
			data = d.data;
			return *this;
		}
		
		BlockStateValue &operator=(int32_t v)
		{
			type = TYPE_INT;
			data.iv = v;
			
			return *this;
		}
		
		BlockStateValue &operator=(float v)
		{
			type = TYPE_FLOAT;
			data.fv = v;
			
			return *this;
		}
		
		BlockStateValue &operator=(const std::string &v)
		{
			type = TYPE_STRING;
			data.sv = v;
			
			return *this;
		}
		
		template<typename AS>
		AS as() const
		{
			switch(type)
			{
				case TYPE_FLOAT:
					return BlockStateValueConvert<float, AS>::to(data.fv);
					
				case TYPE_INT:
					return BlockStateValueConvert<int, AS>::to(data.iv);
					
				case TYPE_NONE:
					return BlockStateValueConvert<void, AS>::to();
					
				case TYPE_STRING:
					return BlockStateValueConvert<std::string, AS>::to(data.sv);
			}
			
			return BlockStateValueConvert<void, AS>::to();
		}
		
		float asFloat() const
		{
			return this->as<float>();
		}
		
		int32_t asInt() const
		{
			return this->as<int32_t>();
		}
		
		std::string asString() const
		{
			return this->as<std::string>();
		}
		
		// cast operations
		operator int32_t() const { return this->as<int32_t>(); }
		operator float() const { return this->as<float>(); }
		operator std::string() const { return this->as<std::string>(); }
		
		bool operator==(const BlockStateValue &v)
		{
			switch(type)
			{
				case TYPE_FLOAT:
					return data.fv == v.asFloat();
					
				case TYPE_INT:
					return data.iv == v.asInt();
					
				case TYPE_NONE:
					return type == v.type;
					
				case TYPE_STRING:
					return data.sv == v.asString();
			}
			
			return false;
		}
		
	private:
		Type type;
		struct DATA {
			DATA() : iv(0) {}
			DATA(int32_t v) : iv(v) {}
			DATA(float v) : fv(v) {}
			DATA(const std::string &v) : sv(v) {}
			union {
				int32_t iv;
				float fv;
			};
			
			std::string sv;
		} data;
};

template<>
class BlockStateValueMapType<BlockStateValue::TYPE_FLOAT>
{
	typedef float type;
};

template<>
class BlockStateValueMapType<BlockStateValue::TYPE_INT>
{
	typedef int32_t type;
};

template<>
class BlockStateValueMapType<BlockStateValue::TYPE_NONE>
{
	typedef void type;
};

template<>
class BlockStateValueMapType<BlockStateValue::TYPE_STRING>
{
	typedef std::string type;
};

#endif /* BLOCK_STATE_VALUE_H_GUARD */
