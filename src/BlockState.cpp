#include "BlockState.h"

#include <algorithm>

bool BlockState::setStateOptions(const std::string &k, const std::vector<BlockStateValue> &opts)
{
	state_option_map[k] = opts;
	return true;
}

bool BlockState::has(const std::string &k) const
{
	if(state_option_map.count(k))
		return true;
	
	if(data.count(k))
		return true;
	
	return false;
}

bool BlockState::set(const std::string &k, const BlockStateValue &v)
{
	auto opt_it = state_option_map.find(k);
	if(opt_it != state_option_map.end())
	{
		// we have a list of valid options
		auto &opts = opt_it->second;
		
		if(std::find(opts.begin(), opts.end(), v) == opts.end())
			// we have options, but v isn't in the list...
			return false;
	}
	
	data[k] = v;
	
	return true;
}

bool BlockState::set(const std::string &k, int32_t iv)
{
	return set(k, BlockStateValue(iv));
}

bool BlockState::set(const std::string &k, float fv)
{
	return set(k, BlockStateValue(fv));
}

bool BlockState::set(const std::string &k, const std::string &sv)
{
	return set(k, BlockStateValue(sv));
}

const BlockStateValue &BlockState::operator[](const std::string &k) const // rhs
{
	return get(k);
}

BlockStateValue &BlockState::operator[](const std::string &k) // lhs
{
	auto it = data.find(k);
	if(it != data.end())
		return it->second;
	
	data.emplace(k, BlockStateValue());
	
	return data[k];
}



