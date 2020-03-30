#pragma once
#include "Prime_Number.h"
#include <string>
#include <vector>
using namespace std;
class Team 
{
private:
	Prime_Number PrimeNumber;
	string teamName;
	vector <int> Players; 
	int numPlayers;
	int Goals;
	int playerNumber;
public:
	Team();
	~Team();
	Team(string);

	void SetTeamName(string);
	string GetTeamName();
	bool SetNumPlayers(int);
	int GetNumPlayers();
	Prime_Number getPrimeNumber();
	int GetPlayers(int);
	void  SetPlayers(int);
	void SetGoals();
	int GetGoals();

};

