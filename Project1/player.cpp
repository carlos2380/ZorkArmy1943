#include "Player.h"
#include "Room.h"


Player::Player()
{
	ttype = PLAYER_TYPE;
}


Player::~Player()
{
	ttype = PLAYER_TYPE;
}

Room* Player::GetRoom()
{
	return room;
}

void Player::SetRoom(Room &room) //: room(&room) -- Not Accepted Here --
{
	this->room = &room;
}

void Player::Look()
{
	room->Look();
}
