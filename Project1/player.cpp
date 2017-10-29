#include "Player.h"
#include "Room.h"


Player::Player()
{
	ttype = PLAYER_TYPE;
}

Player::Player(const char* name, const char* description, int health, CretureStat stat)
: Creature(name, description,health,stat)
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

void Player::Move(const string& place)
{
	room->MovePlayer(place);
}
