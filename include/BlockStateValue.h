#ifndef BLOCK_STATE_VALUE_H_GUARD
#define BLOCK_STATE_VALUE_H_GUARD

#include "BlockStateValueConvert.h"

template <typename T, class Enable = void>
struct BlockStateValuePickType;

template <typename T>
class BlockStateValue;

class BlockStateValueBase
{
	public:
		enum { TYPE_NONE = 0, TYPE_INT, TYPE_FLOAT, TYPE_STRING } Type;
		
		BlockStateValueBase(Type t = TYPE_NONE) : type(t) { }
		
		template<typename T>
		BlockStateValue<T> *cast()
		{	
			switch(type)
			{
				case TYPE_INT:
				case TYPE_FLOAT:
				case TYPE_STRING:
					break;
					
				default:
					return nullptr;
			}
			
			return (BlockStateValue<T>*)this;
		}
		
		template<typename AS>
		AS as()
		{
			
		}
		
		int32_t asInt()
		{
			switch(type)
			{
				case TYPE_INT:
					return this->cast<int32_t>()->value();
					
				case TYPE_FLOAT:
					return this->cast<float>()->as<int32_t>();
					
				case TYPE_STRING:
					return this->cast<std::string>()->as<int32_t>();
					
				default:
					return 0;
			}
			
			return 0;
		}
		
		float asFloat()
		{
			switch(type)
			{
				case TYPE_INT:
					return this->cast<int32_t>()->as<float>();
					
				case TYPE_FLOAT:
					return this->cast<float>()->value();
					
				case TYPE_STRING:
					return this->cast<std::string>()->as<float>();
					
				default:
					return 0.0;
			}
			
			return 0.0;
		}
		
		std::string asString()
		{
			switch(type)
			{
				case TYPE_INT:
					return this->cast<int32_t>()->as<std::string>();
					
				case TYPE_FLOAT:
					return this->cast<float>()->as<std::string>();
					
				case TYPE_STRING:
					return this->cast<std::string>()->value();
					
				default:
					return std::string();
			}
			
			return std::string();
		}
		
	private:
		Type type;
		
		const static BlockStateValue<void*> invalid_value;
};


class BlockStateValue
{
	public:
		enum { TYPE_NONE = 0, TYPE_INT, TYPE_FLOAT, TYPE_STRING } Type;
		
		BlockStateValue() : type(TYPE_NONE) { }
		BlockStateValue(int32_t iv) : type(TYPE_INT) { data.iv = iv; }
		BlockStateValue(float fv) : type(TYPE_FLOAT) { data.fv = fv; }
		BlockStateValue(const std::string &sv) : type(TYPE_STRING) { data.sv = sv; }
		
		BlockStateValue(const BlockStateValue<T> &d) : type(d.type), data(d.data) { }
		
		~BlockStateValue()
		{ }
		
		BlockStateValue<T> &operator=(const BlockStateValue<T> &d)
		{
			type = d.type;
			data = d.data;
			return *this;
		}
		
		BlockStateValue<T> &operator=(int32_t v)
		{
			type = TYPE_INT;
			data.iv = v;
			
			return *this;
		}
		
		BlockStateValue<T> &operator=(float v)
		{
			type = TYPE_FLOAT;
			data.fv = v;
			
			return *this;
		}
		
		BlockStateValue<T> &operator=(const std::string &v)
		{
			type = TYPE_STRING;
			data.sv = v;
			
			return *this;
		}
		
		const T &value() const { return data; }
		
		template<typename AS>
		AS as()
		{
			return BlockStateValueConvert<T, AS>::to(data);
		}
		
		float asFloat()
		{
			return this->as<float>();
		}
		
		int32_t asInt()
		{
			return this->as<int32_t>();
		}
		
		std::string asString()
		{
			return this->as<std::string>();
		}
		
		// cast operations
		operator int32_t() const { return this->as<int32_t>(); }
		operator float() const { return this->as<float>(); }
		operator std::string() const { return this->as<std::string>(); }
		
	private:
		Type type;
		struct {
			union {
				int32_t iv;
				float fv;
				std::string sv;
			};
		} data;
};

template <typename T, typename std::enable_if<std::is_integral<T>::value>::type>
struct BlockStateValuePickType {
	typedef typename BlockStateValue::Type Type;
	const static Type value = TYPE_INT;
}

template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type>
struct BlockStateValuePickType {
	typedef typename BlockStateValue::Type Type;
	const static Type value = TYPE_FLOAT;
}

template <typename T, typename std::enable_if<std::is_same<std::remove_reference<T>::type, std::string>::value>::type>
struct BlockStateValuePickType {
	typedef typename BlockStateValue::Type Type;
	const static Type value = TYPE_STRING;
}

template <typename T>
struct BlockStateValuePickType {
	typedef typename BlockStateValue::Type Type;
	const static Type value = TYPE_NONE;
}

#endif /* BLOCK_STATE_VALUE_H_GUARD */
