#include "place.h"
#include "player.h"
#include <iostream>
#include "weapond.h"
#include "ncp.h"
#include "globals.h"


Place::Place()
{
	visited = false;
}

Place::Place(const char* name, const char* description, const char* descriptionPlayer, int visibility, bool accessible)
: Entity(name, description), descriptionPlayer(descriptionPlayer), visibility(visibility), accessible(accessible)
{
	ttype = PLACE_TYPE;
	visited = false;
}

Place::~Place()
{
}

bool Place::IsVisited()
{
	return visited;
}

void Place::SetVisited(bool visited)
{
	this->visited = visited;
}

int Place::GetVisibility()
{
	return visibility;
}

bool Place::IsAccessible()
{
	return accessible;
}

void Place::SetAccessible(bool accessible)
{
	this->accessible = accessible;
}

string Place::GetDesciptionPlayer()
{
	return descriptionPlayer;
}

void Place::Look()
{
	if(visited)
	{
		for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
		{
			if ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE || (*it)->GetType() == NCP_TYPE || (*it)->GetType() == CREATURE_TYPE) {
				cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << " in " << GetName() << endl;
			}
		}
	}else
	{
		for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
		{
			if ((*it)->GetType() == NCP_TYPE) {
				cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << " in " << GetName() << endl;
			}
		}
	}
}

bool Place::TakeToPlayer(const string& name, Player &player)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE)) {
			player.AddItem(*(*it));
			contains.remove(*it);
			return true;
		}
	}
	return false;
}

bool Place::Stats(const string& name)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == CREATURE_TYPE || (*it)->GetType() == NCP_TYPE || (*it)->GetType() == PLAYER_TYPE)) {
			((Creature*)(*it))->Stats();
			return true;
		}
	}
	return false;
}

bool Place::EnemyAttacking()
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() == ATTACKING) {
			return true;
		}
	}
	return false;
}

void Place::TurnAttackEnemies(Player& player)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() == ATTACKING) {
			if (((Weapond*)((Ncp*)(*it))->GetEquip())->GetAmmo() > 0)
			{
				int dammage = ((Ncp*)(*it))->GetDammageAttack();
				player.Strike(dammage);
				if (dammage > 0) cout << (*it)->GetName() << " attack you! -" << dammage << " (" << player.GetHealth() << " points of life)" << endl;
				else cout << (*it)->GetName() << " attack you but failed!" << endl;
			}
			else
			{
				cout << (*it)->GetName() << "attaking you but no have ammo!" << endl;
			}
		}
	}
}

void Place::EnemiesSeekPlayer()
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() != DEAD) {
			if (RandomNumber(0, 100) < 20)
			{
				((Ncp*)(*it))->SetStat(ATTACKING);
				cout << "Enemy " << (*it)->GetName() << " see you!" << endl;
			}
		}
	}
}

int Place::Rescue(const string& name)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (((*it)->GetType() == NCP_TYPE) && ((Creature*)(*it))->GetStat() != DEAD) {
			cout << "you cant rescue, enemies alive!" << endl;
			return 0;
		}
	}
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == CREATURE_TYPE) && ((Creature*)(*it))->GetStat() != DEAD) {
			return 1;
		}
	}
	return -1;
}


