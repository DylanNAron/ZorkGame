#pragma once
#include <string>
#include <json/json.h>
#include "Commands.h"


namespace ZorkGame {

	class Room
	{
	public:
		Room(Json::Value RoomJson); //default constructor

		Room();

		inline const std::string& GetName() {
			return _name;
		}

		inline const std::string& GetDescription() {
			return _description;
		}

		inline const std::map<ZorkGame::Commands, Room&> GetNeighbors() {
			return _neighbors;
		}

		inline const std::map<ZorkGame::Commands, std::string> GetNeighborsStrings() {
			return _neighborsStrings;
		}

		void InsertNeighbor(Commands command, Room& neighbor);

	private:
		std::string _name;
		std::string _description;
		std::map<ZorkGame::Commands, std::string> _neighborsStrings; //this comes from json
		std::map<ZorkGame::Commands, Room&> _neighbors;

	};

}