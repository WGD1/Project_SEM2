#include "Team.h"
Team::Team() :PrimeNumber()
{
	this->teamName = " ";
	this->Players.clear();
	this->playerNumber = 0;
	this->Goals = 0;
	this->numPlayers = 0;
}
Team::Team(string name)
{
	this->teamName = name ;
	this->Players.clear();
	this->playerNumber = 0;
	this->Goals = 0;
	this->numPlayers = 0;
}
Team::~Team()
{
}

void Team::SetTeamName(string name)
{
	try
	{
		this->teamName = name;
	
	}
	catch (const exception&)
	{
		
	}

}
string Team::GetTeamName()
{
	return this->teamName;
}
bool Team::SetNumPlayers(int numPlayers)
{
	if (numPlayers < 3 || numPlayers >11)
	{
		return false;
	}
	else
	{
		this->numPlayers = numPlayers;
		return true;
	}
	
}

int Team::GetNumPlayers()
{
	return this->numPlayers;
}
Prime_Number Team::getPrimeNumber()
{
	return this->PrimeNumber;
}
int Team::GetPlayers(int num)
{
	return this->Players[num];
}
void Team::SetPlayers(int players)
{
	this->Players.push_back(players);

}

void Team::SetGoals()
{
	this->Goals = this->Goals + 1;
}
int Team::GetGoals()
{
	return this->Goals;
}