#include "Player.h"
#include "Room.h"
#include <iostream>


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

void Player::Take(const string& name)
{
	if(room->TakeToPlayer(name, *this))
	{
		cout << name << " taked!" << endl;
	}else
	{
		cout << "No item called " << name << " for take." << endl;
	}
}