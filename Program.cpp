#include <json/json.h>
#include <fstream>
#include "Commands.h"
#include <iostream>
#include "World.h"
using namespace ZorkGame;
using namespace std;

/*
*	Data Driven Zork Game in C++ 
*   Created By Dylan Aron
*   11/9/22
*/

int main() 
{
	bool playing = true;
	Commands currentCommand;
	World zorkWorld;
	string input;
	cout << "Welcome To Dylan's Zork Game\n";
	cout << "You are in " << zorkWorld.GetCurrentRoomName() << "\n";


	while (playing) {

		cout << "Type a command: ";
		cin >> input;
		currentCommand = ToCommand(toUppercase(input));

		//cout << CommandsEnumString[(int)currentCommand]; //DEBUG TO CHECK COMMAND INPUT

		if (currentCommand == Commands::Quit) {
			playing = false;
		}
		else {
			zorkWorld.PlayerAction(currentCommand);
		}

	}
}