#include "World.h"
#include <fstream>
#include <iostream>
#include <json/json.h>
using namespace std;

/*
* The World class reads json object in Game.json and creates Room objects and connects them
* in the world are functions for the player to interact with based on given commands
*/

namespace ZorkGame {

	World::World()
	{
		ifstream jsonStream{ R"(Game.json)" };
		if (!jsonStream.good())
		{
			throw runtime_error("Could not open file");
		}

		Json::Value root;
		jsonStream >> root;

		const Json::Value& startingLocationValue = root["StartingLocation"];

		Json::Value& world = root["World"];
		Json::Value& rooms = world["Rooms"];


		//Generate Rooms for the World
		for (Json::Value& roomJson : rooms)
		{
			Room curRoom = Room(roomJson);
			roomsMap.insert({ curRoom.GetName(), curRoom });
		}

		map<string, Room>::iterator roomsIterator;
		//Connect the Rooms Neighbors!
		for (roomsIterator = roomsMap.begin(); roomsIterator != roomsMap.end(); ++roomsIterator)
		{
			Room& curRoom = roomsIterator->second;
			map<Commands, string>::iterator neighborStringsIt;
			map<Commands, string> neighborStrings = curRoom.GetNeighborsStrings();
			for (neighborStringsIt = neighborStrings.begin(); neighborStringsIt != neighborStrings.end(); ++neighborStringsIt) {
				Room& neighborRoom = roomsMap.at((neighborStringsIt->second));
				curRoom.InsertNeighbor(neighborStringsIt->first, neighborRoom);
			}
		}

		//set starting room
		currentRoom = roomsMap.at(startingLocationValue.asString());

	}


	std::map<ZorkGame::Commands, Room&> tempNeighborsOfRoom;

	void World::PlayerAction(Commands command)
	{
		tempNeighborsOfRoom = currentRoom.GetNeighbors();

		switch (command)
		{
		case Commands::Look:
			cout << currentRoom.GetDescription() << "\n";
			break;
		case Commands::North:
			MoveRooms(tempNeighborsOfRoom, command);
			break;
		case Commands::East:
			MoveRooms(tempNeighborsOfRoom, command);
			break;
		case Commands::South:
			MoveRooms(tempNeighborsOfRoom, command);
			break;
		case Commands::West:
			MoveRooms(tempNeighborsOfRoom, command);
			break;
		case Commands::Up:
			MoveRooms(tempNeighborsOfRoom, command);
			break;
		case Commands::Down:
			MoveRooms(tempNeighborsOfRoom, command);
			break;
		case Commands::Quit:
			//Quit Game
			break;
		case Commands::Reward:
			IncreaseScore();
			break;
		case Commands::Score:
			cout << _score << "\n";
			break;
		default:
			cout << "Unknown Command" << "\n";
			break;
		}

	}

	void World::MoveRooms(std::map<ZorkGame::Commands, Room&>  &tempNeighborsOfRoom, Commands command) {

		if (tempNeighborsOfRoom.find(command) == tempNeighborsOfRoom.end()) {
			//not found
			cout << "You cannot go that way" << "\n";
		}
		else {
			currentRoom = tempNeighborsOfRoom.at(command);
			cout << "You have moved to " << currentRoom.GetName() << "\n";
		}

	}


}


