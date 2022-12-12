#pragma once
#include <vector>
#include "Room.h"
namespace ZorkGame {

	class World
	{
	public:
		World(); //build world of each room in json
		
		void PlayerAction(Commands cmnd);

		inline const int GetScore() {
			return _score;
		}

		void inline IncreaseScore() {
			_score++;
		}

		inline const std::string GetCurrentRoomName() {
			return currentRoom.GetName();
		}

	private:
		Room roomInitializer;
		Room& currentRoom = roomInitializer; //why do I need to do this???
		std::map<std::string, Room> roomsMap;
		int _score = 0;

		void MoveRooms(std::map<ZorkGame::Commands, Room&>& tempNeighborsOfRoom, Commands command);

	};

}