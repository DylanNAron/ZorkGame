#include "Commands.h";
#include <map>;
using namespace std;

/*
* The commands file contains the enum for all possible commands for the player
* as well as the appropriate functions to converted inputted strings to commands
*/

namespace ZorkGame
{

	static const map<string, ZorkGame::Commands>commandMap = {
		{"LOOK", Commands::Look},
		{"NORTH", Commands::North},
		{"N", Commands::North},
		{"EAST", Commands::East},
		{"E", Commands::East},
		{"SOUTH", Commands::South},
		{"S", Commands::South},
		{"WEST", Commands::West},
		{"W", Commands::West},
		{"UP", Commands::Up},
		{"U", Commands::Up},
		{"CLIMB", Commands::Up},
		{"DOWN", Commands::Down},
		{"D", Commands::Down},
		{"DESCEND", Commands::Down},
		{"QUIT", Commands::Quit},
		{"Q", Commands::Quit},
		{"Exit", Commands::Quit},
		{"BYE", Commands::Quit},
		{"REWARD", Commands::Reward},
		{"SCORE", Commands::Score},
	};

	Commands ToCommand(string str) {
		str = toUppercase(str);
		Commands commandToCheck = commandMap.find(str)->second;

		switch (commandToCheck)
		{
			case Commands::Look:
				return Commands::Look;
				break;
			case Commands::North:
				return Commands::North;
				break;
			case Commands::East:
				return Commands::East;
				break;
			case Commands::South:
				return Commands::South;
				break;
			case Commands::West:
				return Commands::West;
				break;
			case Commands::Up:
				return Commands::Up;
				break;
			case Commands::Down:
				return Commands::Down;
				break;
			case Commands::Quit:
				return Commands::Quit;
				break;
			case Commands::Reward:
				return Commands::Reward;
				break;
			case Commands::Score:
				return Commands::Score;
				break;
			default:
				return Commands::Unknown;
				break;
		}
	}
}