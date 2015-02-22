#ifndef BLOCK_STATE_H_GUARD
#define BLOCK_STATE_H_GUARD

#include <string>
#include <unordered_map>
#include <vector>

#include "BlockStateValue.h"

class BlockState
{
	public:
		BlockState() : name_("missing"), valid_(false) { }
		BlockState(const std::string &n) : name_(n), valid_(true) { }
		~BlockState() { }
		
		const std::string &name() { return name_; }
		bool setStateOptions(const std::string &k, const std::vector<BlockStateValue> &opts);
		
		bool has(const std::string &k) const;
		
		bool set(const std::string &k, const BlockStateValue &v);
		bool set(const std::string &k, int32_t iv);
		bool set(const std::string &k, float fv);
		bool set(const std::string &k, const std::string &sv);
		
		// get as
		
		const BlockStateValue &get(const std::string &k) const
		{
			auto it = data.find(k);
			if(it != data.end())
				return it->second;
			
			return BlockStateValue::NullValue;
		}
		
		const BlockStateValue &operator[](const std::string &k) const; // rhs
		BlockStateValue &operator[](const std::string &k); // lhs
		
	private:
		std::string name_;
		bool valid_;
		std::unordered_map<std::string, std::vector<BlockStateValue>> state_option_map;
		std::unordered_map<std::string, BlockStateValue> data;
};

#endif /* BLOCK_STATE_H_GUARD */
