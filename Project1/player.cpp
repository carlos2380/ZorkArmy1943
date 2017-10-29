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

void Player::Inventary()
{
	cout << endl << "Inventary:" << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
	}
	cout << endl;
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

void Player::Unequip()
{
	if(equip != nullptr)
	{
		cout << equip->GetName() << " unequiped!" << endl;
	}
	else cout << "unequiped!" << endl;
	equip = nullptr;
}

void Player::Equip(const string& name)
{
	bool found = false;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end() && !found; ++it)
	{
		if(!(*it)->GetName().compare(name) && (*it)->GetType() == WEAPOND_TYPE)
		{
			equip = *it;
			cout << name << " equiped!" << endl;
			found = true;
		}
	}
	if(!found)
	{
		cout << "No item called " << name << " can equip!" << endl;
	}
}

