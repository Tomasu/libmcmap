#ifndef BLOCK_STATE_VALUE_CONVERT_H_GUARD
#define BLOCK_STATE_VALUE_CONVERT_H_GUARD

#include <string>
#include <type_traits>
#include <cstring>
#include <memory.h>
#include <cstdlib>

template<typename FROM, typename TO, class Enable = void>
struct BlockStateValueConvert;

template<typename FROM, typename TO>
struct BlockStateValueConvert<FROM, TO, typename std::enable_if<std::is_same<FROM, TO>::type>::type>
{
	static TO &to(const FROM &from)
	{
		return from;
	}
};

template<typename FROM, typename TO>
struct BlockStateValueConvert<FROM, TO, typename std::enable_if<std::is_integral<FROM>::value && std::is_floating_point<TO>::value>::type>
{
	static TO to(const FROM &from)
	{
		return (TO)from;
	}
};

template<typename FROM, typename TO>
struct BlockStateValueConvert<FROM, TO, typename std::enable_if<std::is_floating_point<FROM>::value && std::is_integral<TO>::value>::type>
{
	static TO to(const FROM &from)
	{
		return (TO)from;
	}
};

template<>
struct BlockStateValueConvert<std::string, float>
{
	static float to(const std::string &from)
	{
		return strtof(from.c_str(), nullptr);
	}
};

template<>
struct BlockStateValueConvert<std::string, int32_t>
{
	static int32_t to(const std::string &from)
	{
		return strtol(from.c_str(), nullptr, 10);
	}
};

template<>
struct BlockStateValueConvert<float, std::string>
{
	static std::string to(const float &from)
	{
		char buff[128];
		memset(buff, 0, sizeof(buff));
		
		snprintf(buff, sizeof(buff)-1, "%f", from);
		
		return std::string(buff);
	}
};

template<>
struct BlockStateValueConvert<int32_t, std::string>
{
	static std::string to(const float &from)
	{
		char buff[128];
		memset(buff, 0, sizeof(buff));
		
		snprintf(buff, sizeof(buff)-1, "%d", from);
		
		return std::string(buff);
	}
};

template<>
struct BlockStateValueConvert<void, int32_t>
{
	static int32_t to()
	{
		return 0;
	}
};

template<>
struct BlockStateValueConvert<void, float>
{
	static float to()
	{
		return 0.0;
	}
};

template<>
struct BlockStateValueConvert<void, std::string>
{
	static std::string to()
	{
		return "(none)";
	}
};

#endif /* BLOCK_STATE_VALUE_CONVERT_H_GUARD */
