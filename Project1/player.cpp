#include "Player.h"
#include "Room.h"
#include <iostream>
#include "weapond.h"
#include "Item.h"


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

void Player::Attack(const string& name)
{
	bool nextStep = true;
	if(equip)
	{
		if(((Weapond*) equip)->GetAmmo() <= 0)
		{
			cout << "You don't have ammo for shoot with " << equip->GetName() << "!" << endl;
			nextStep = false;
		}
	}
	if(nextStep)
	{
		bool shoot = room->PlayerAttackTo(name, *this);
		if(shoot && equip != nullptr)
		{
			if(((Weapond*)equip)->IsRemote())
			{
				equip->RemoveItem(((Weapond*)equip)->GetTypeAmmo());
			}
		}
	}
}

void Player::Stats(const string& name)
{
	room->Stats(name);
}

void Player::Reload()
{
	if (equip != nullptr)
	{
		if (((Weapond*)equip)->IsRemote())
		{
			list<Entity*>::iterator it = contains.begin();
			for (int i = 0; i < contains.size(); ++i)
			{
				if(!(*it)->GetName().compare(((Weapond*)equip)->GetTypeAmmo()))
				{
					Item* item = (Item*) GetEntity((*it)->GetName(), ITEM_TYPE);
					equip->AddItem(*item);
					RemoveItem((*it)->GetName());
					++i;
				}
				if(i <  contains.size())++it;
			}
		}
	}
}
