#pragma once
#include<assert.h>
#include <string>
#include <algorithm>

namespace ZorkGame
{
	
	  const static std::string CommandsEnumString[]{
		"Look",
		"North",
		"East",
		"South",
		"West",
		"Up",
		"Down",
		"Quit",
		"Reward",
		"Score",
		"Unknown"
	};


	enum class Commands
	{
		Look,
		North,
		East,
		South,
		West,
		Up,
		Down,
		Quit,
		Reward,
		Score,
		Unknown
	};

	inline std::string toUppercase(std::string str) {
		std::transform(str.begin(), str.end(), str.begin(), toupper);
		return str;
	}

	Commands ToCommand(std::string commandString);

}