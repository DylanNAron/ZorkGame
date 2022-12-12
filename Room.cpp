#include "Room.h"
#include <iostream>
using namespace std;

/*
* The Room class is the basis for each room within our world to be generated
* Room contains description, name , and its neighboring rooms
* 
*/

namespace ZorkGame
{

	Room::Room()
	{
		//default
	}

	void Room::InsertNeighbor(Commands command, Room& neighbor)
	{
		_neighbors.insert({ command, neighbor });
	}

	Room::Room(Json::Value RoomJson)
	{
		_name = RoomJson["Name"].asString();
		_description = RoomJson["Description"].asString();
		Json::Value& neighbors = RoomJson["Neighbors"];

	
		string curDirection = "North";
		if (!neighbors[curDirection].isNull())
		{
			_neighborsStrings.insert({ ToCommand(curDirection), neighbors[curDirection].asString()});
		}
		curDirection = "East";
		if (!neighbors[curDirection].isNull())
		{
			_neighborsStrings.insert({ ToCommand(curDirection), neighbors[curDirection].asString()});
		}
		curDirection = "South";
		if (!neighbors[curDirection].isNull())
		{
			_neighborsStrings.insert({ ToCommand(curDirection), neighbors[curDirection].asString()});
		}
		curDirection = "West";
		if (!neighbors[curDirection].isNull())
		{
			_neighborsStrings.insert({ ToCommand(curDirection), neighbors[curDirection].asString()});
		}
		curDirection = "Up";
		if (!neighbors[curDirection].isNull())
		{
			_neighborsStrings.insert({ ToCommand(curDirection), neighbors[curDirection].asString()});
		}
		curDirection = "Down";
		if (!neighbors[curDirection].isNull())
		{
			_neighborsStrings.insert({ ToCommand(curDirection), neighbors[curDirection].asString()});
		}

	}
};
