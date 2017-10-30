#include "Room.h"
#include "Player.h"
#include <iostream>
#include "place.h"
#include "Item.h"
#include "creature.h"
#include "Ncp.h"
#include "weapond.h"
#include "globals.h"

using namespace std;

Room::Room()
{
	ttype = ROOM_TYPE;
}

Room::Room(const char* name, const char* description) : Entity(name, description)
{
	ttype = ROOM_TYPE;
	firstPlace = -1;
	currentPlayerPlace = -1;
}

Room::Room(const char* name, const char* description, vector<Place*> &places, int firstPlace) : Entity(name, description)
{
	ttype = ROOM_TYPE;
	this->places = places;
	if (&firstPlace != nullptr) {
		if (firstPlace < places.size())
		{
			this->firstPlace = firstPlace;
		}
		else
		{
			firstPlace = -1;
			currentPlayerPlace = -1;
		}
	}
}

Room::~Room()
{
}


void Room::Look()
{
	cout << endl << name << ", " << description << endl << endl;
	
	if(places.size()>0)cout << "you can walk to the next places" << endl;
	for (int i = 0; (i < places.size()); ++i)
	{
		cout << "\t" <<places[i]->GetName() << ", " << places[i]->GetDescription() << endl;
	}

	cout << endl << "There are: " << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE || (*it)->GetType() == NCP_TYPE || (*it)->GetType() == CREATURE_TYPE) {
			cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		places[i]->Look();
	}

	cout << endl << "You can go to: " << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if ((*it)->GetType() == EXIT_TYPE) {
			cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
		}
	}

	if (currentPlayerPlace >= 0)
	{
		cout << endl << places[currentPlayerPlace]->GetDesciptionPlayer() << endl;
	}
	else
	{
		cout << endl << "You are in " << GetName() << endl;
	}
	cout << endl;
}

void Room::EnterCreature(Entity &entity)
{
	if(firstPlace >= 0)
	{
		places[firstPlace]->AddItem(entity);
	}else
	{
		AddItem(entity);
	}
}

void Room::ExitCreature(string &name)
{
	if(!RemoveItem(name))
	{
		bool deleted = false;
		for(int i = 0; (i < places.size()) && (!deleted); ++i)
		{
			deleted = places[i]->RemoveItem(name);
		}
	}
}

void Room::EnterPlayer(Entity& entity)
{
	if (firstPlace >= 0)
	{
		currentPlayerPlace = firstPlace;
		places[firstPlace]->SetVisited(true);
	}
	else
	{
		currentPlayerPlace = -1;
	}
	AddItem(entity);
}

void Room::ExitPlayer(string& name)
{
	RemoveItem(name);
}

void Room::MovePlayer(const string& place)
{
	bool found = false;
	for (int i = 0; (i < places.size()) && (!found); ++i)
	{
		if(!places[i]->GetName().compare(place))
		{
			if(places[i]->IsAccessible())
			{
				places[i]->SetVisited(true);
				currentPlayerPlace = i;
				cout << places[i]->GetDesciptionPlayer() << endl;
			}else
			{
				cout << "You can't move to " << place << "!" << endl;
			}
			found = true;
		}
	}
	if(!found)
	{
		cout << "Not exist place called " << place << "!" << endl;
	}
}

bool Room::TakeToPlayer(const string& name, Player &player)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE)) {
			player.AddItem(*(*it));
			contains.remove(*it);
			return true;
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		if(places[i]->IsVisited())
		{
			if(places[i]->TakeToPlayer(name, player)) {
				return true;
			}
		}
	}
	return false;
}

bool Room::PlayerAttackTo(const string& name, Player& player)
{
	Ncp* enemy = (Ncp*)GetEntity(name, NCP_TYPE);
	if(enemy != nullptr)
	{
		if (enemy->isAlive())
		{
			int dammage = player.GetDammageAttack();
			if(dammage > 0)
			{
				enemy->Strike(dammage);
				cout << enemy->GetName() << " Striked! -" << dammage << " (" << enemy->GetHealth() << " points of life)" << endl;
				return true;
			}
			else
			{
				enemy->Strike(dammage);
				cout << "You attack to " << enemy->GetName() << " but failed!" << endl;
				return true;
			}
		}
		else
		{
			cout << name << " is dead!" << endl;
			return false;
		}
	}
	for(int i = 0; i < places.size(); ++i)
	{
		Ncp* enemy = (Ncp*)places[i]->GetEntity(name, NCP_TYPE);
		if (enemy != nullptr)
		{
			if (enemy->isAlive())
			{
				if((Weapond*) player.GetEquip() == nullptr)
				{
					if (currentPlayerPlace != i)
					{
						cout << name << " is to far to attack unequiped!" << endl;
						return false;
					}
				}
				else if(((Weapond*) player.GetEquip())->IsRemote() == false)
				{
					if(currentPlayerPlace != i)
					{
						cout << name << " is to far to attack with " << player.GetEquip()->GetName() << "!" << endl;
						return false;
					}
				}
				int dammage = player.GetDammageAttack();
				if (dammage > 0)
				{
					enemy->Strike(dammage);
					cout << enemy->GetName() << " Striked! -" << dammage << " (" << enemy->GetHealth() << " points of life)" << endl;
					return true;
				}
				else
				{
					enemy->Strike(dammage);
					cout << "You attack to " << enemy->GetName() << " but failed!" << endl;
					return true;
				}
			}
			else
			{
				cout << name << " is dead!" << endl;
				return false;
			}
		}
	}
	cout << "Not " << name << " for attack!" << endl;
	return false;
}

bool Room::Stats(const string& name)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == CREATURE_TYPE || (*it)->GetType() == NCP_TYPE || (*it)->GetType() == PLAYER_TYPE)) {
			((Creature*)(*it))->Stats();
			return true;
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		if(places[i]->Stats(name)) return true;
	}
	
	cout << "No " << name << " with states!" << endl;
	return false;
}

bool Room::EnemyAttacking()
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() == ATTACKING) {
			return true;
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		if (places[i]->EnemyAttacking()) return true;
	}
	return false;
}

void Room::TurnAttackEnemies(Player& player)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() == ATTACKING) {
			if(((Weapond*)((Ncp*)(*it))->GetEquip())->GetAmmo() > 0)
			{
				int dammage = ((Ncp*)(*it))->GetDammageAttack();
				player.Strike(dammage);
				if(dammage > 0) cout << (*it)->GetName() << " attack you! -" << dammage << " (" << player.GetHealth() << " points of life)" << endl;
				else cout << (*it)->GetName() << " attack you but failed!" << endl;
			}else
			{
				cout << (*it)->GetName() << "attaking you but no have ammo!" << endl;
			}
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		places[i]->TurnAttackEnemies(player);
	}

}

void Room::EnemiesSeekPlayer()
{

	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() != DEAD) {
			if(RandomNumber(0,100) < 20)
			{
				((Ncp*)(*it))->SetStat(ATTACKING);
				cout << "Enemy " << (*it)->GetName() << " see you!" << endl;
			}
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		places[i]->EnemiesSeekPlayer();
	}
}

bool Room::Rescue(const string& name)
{
	bool enemies = false;
	bool host = false;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() != DEAD) {
			enemies =  true;
		}
	}
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == CREATURE_TYPE) && ((Creature*)(*it))->GetStat() != DEAD) {
			host = true;
		}
	}

	for (int i = 0; (i < places.size()); ++i)
	{
		int ret = places[i]->Rescue(name);
		if(ret == 1)
		{
			host = true;
		}else if(ret == 0)
		{
			enemies = true;
		}
	}
	if (host)
	{
		if (enemies)
		{
			cout << "you cant rescue, enemies alive!" << endl;
			return true;
		}
		return true;
	}
	else  {
		
		cout << "No host " << name << " found!" << endl;
		return false;
	}

}
