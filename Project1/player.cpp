#include "Player.h"
#include "Room.h"


Player::Player()
{
}


Player::~Player()
{
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
