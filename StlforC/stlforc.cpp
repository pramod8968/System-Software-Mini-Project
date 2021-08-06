#define BUILD_STL_FOR_C

#include "stlforc.h"


#include <vector>
#include <map>
#include <string>
#include <algorithm>

using cpp_map_t = std::map<std::string, int>;

// pair.first = long long 
// pair.second = std::map<string, int>
using color_map_t = std::pair<color_t, cpp_map_t>;

using map_vector_t = std::vector<color_map_t>;

// a global instance of 
// std::vector<std::pair<long long, std::map<std::string, int>>;
map_vector_t gMapVector;

color_t gColor = 0;

extern "C"
{  
	EXPORTS map_t map_create() 
	{
		color_t color = gColor++;
		gMapVector.emplace_back(color, cpp_map_t{});

		std::sort(gMapVector.begin(), gMapVector.end(),
			[](auto&& left, auto&& right)
			{
				return left.first < right.first;
			});
		return { color, NULL, 0 };

	}
	EXPORTS bool map_delete(map_t* map)
	{
		//std::lower_bound is binary search algorithm
		auto itr = std::lower_bound(gMapVector.begin(),
			gMapVector.end(), color_map_t{ map->color, cpp_map_t {} },
			[](auto&& left, auto&& right)
			{
				return left.first < right.first;
			});
		if (itr != gMapVector.end())
		{
			gMapVector.erase(itr);
			return true;
		}

		return false;
	}

	EXPORTS bool map_get_value(map_t* map)
	{
		auto itr =
			std::lower_bound(gMapVector.begin(),
				gMapVector.end(), color_map_t{ map->color, cpp_map_t{} },
				[](auto&& left, auto&& right)
				{
					return left.first < right.first;
				});

		if (itr != gMapVector.end())
		{
			try
			{
				map->value = itr->second[std::string(map->key)];
				return true;
			}
			catch (const std::exception&)
			{ }
		}

		return false;
	}

	EXPORTS bool map_set_value(map_t* map)
	{
		auto itr =
			std::lower_bound(gMapVector.begin(),
				gMapVector.end(), color_map_t{ map->color, cpp_map_t{} },
				[](auto&& left, auto&& right)
				{
					return left.first < right.first;
				});

		if (itr != gMapVector.end())
		{
			try
			{
				itr->second[std::string(map->key)] = map->value;
				return true;
			}
			catch (const std::exception&)
			{ }
		}

		return false;
	}

}
 