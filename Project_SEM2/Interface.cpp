#include"Interface.h"
#include<string>
#include<iostream>
#include"Game.h"
#include"Team.h"
#include "Error_Handeling.h"
#include <Windows.h>
#include "Dice.h"
using namespace std;

void DrawHeader()
{
	cout << ".______  .______       __ .___  ___. _______      .__   __. __    __    .___  ___..______   _______ .______            _______   ______    ______  .___________..______       ___      __       __      " << endl;
	cout << "|   _  \\ |   _  \\     |  ||   \\/   ||   ____|     |  \\ |  ||  |  |  ||   \\/   ||   _  \\ |   ____||   _  \\          |   ____| /  __  \\  /  __  \\ |           ||   _  \\     /   \\    |  |     |  |     " << endl;
	cout << "|  |_)  ||  |_)  |    |  ||  \\  /  ||  |__        |   \\|  ||  |  |  ||  \\  /  ||  |_)  ||  |__   |  |_)  |         |  |__   |  |  |  ||  |  |  |`---|  |----`|  |_)  |   /  ^  \\   |  |     |  |     " << endl;
	cout << "|   ___/ |      /     |  ||  |\\/|  ||   __|       |  . `  ||  |  |  ||  |\\/|  ||   _  < |   __|  |      /          |   __|  |  |  |  ||  |  |  |    |  |     |   _  <   /  /_\\  \\  |  |     |  |     " << endl;
	cout << "|  |     |  |\\  \\----.|  ||  |  |  ||  |____      |  |\\   ||  `--'  ||  |  |  ||  |_)  ||  |____ |  |\\  \\----.     |  |     |  `--'  ||  `--'  |    |  |     |  |_)  | /  _____  \\ |  `----.|  `----." << endl;
	cout << "| _|     | _| `._____||__||__|  |__||_______|     |__| \\__| \\______/ |__|  |__||______/ |_______|| _| `._____|     |__|      \\______/  \\______/     |__|     |______/ /__/     \\__\\|_______||_______|" << endl;
	cout << "" << endl;
}
void DrawMenu(int width, char drawChar)
{
	string firstAndLastRow(width, drawChar);
	cout << firstAndLastRow << endl;
	cout << "\t\t\t.___  ___. _______ .__   __. __    __    " << endl;
	cout << "\t\t\t|   \\/   ||   ____||  \\ |  ||  |  |  |" << endl;
	cout << "\t\t\t|  \\  /  ||  |__   |   \\|  ||  |  |  |" << endl;
	cout << "\t\t\t|  |\\/|  ||   __|  |  . `  ||  |  |  |" << endl;
	cout << "\t\t\t|  |  |  ||  |____ |  |\\   ||  `--'  |" << endl;
	cout << "\t\t\t|__|  |__||_______||__| \\__| \\______/ " << endl;
	cout << "" << endl;
	cout << "\t\t\tPlease Select what mode you would like to play\n\n";
	cout << "\t\t\t1: One PLayer Game\n";
	cout << "\t\t\t2: Two PLayer Game\n";
	cout << "\t\t\t3: End Game\n\n";
	cout << firstAndLastRow << endl;
}

void OnePlayerGame()
{	
	cout << "\tYou Selected One Player Game\n" << endl;
	Game::Get().getPlayers(1).SetTeamName("AI Player");
	
	string name, NumPlayers,d;
	int NumberOfPlayers = 0, gameType=0, NumGoals = 0,time = 0;

	cout << "\tPlease enter Player ones Name: ";
	cin >> name;
	Game::Get().getPlayers(0).SetTeamName(name);
	system("CLS"); // This will clear the screen ready for the game to being !
	cout << "Please select a Game Type \n\t1:Number of Goals Game \n\t 2:Timed Game" << endl;
	cin >> gameType;
	if (gameType == 1)
	{
		cout << "\tYou selected Number Of Goals\n";
		do
		{// Need to add in the error handling to check that its only numbers

			d = "\t How many goals would you like to play to?";
			CheckVaildUserInput(d, NumGoals);
			
		} while (Game::Get().set_goals_to_win(NumGoals) != 1);

		Game::Get().set_goals_to_win(NumGoals);
		Game::Get().set_time_to_win(-1);
	}
	else
	{
		cout << "\tYou selected a timed game\n";
		do// Need to add in the error handling to check that its only numbers
		{
			d= "\tHow long would you like the game to last?(mins):";
			CheckVaildUserInput(d, time);

		} while (Game::Get().set_time_to_win(time)!= 1);
		Game::Get().set_time_to_win(time);
		Game::Get().set_goals_to_win(-1);

	}

	do
	{
		 d="\tPlease enter the Number of Players on each team (Between 3 & 11): ";
		 CheckVaildUserInput(d,NumberOfPlayers);

	} while ( Game::Get().getPlayers(0).SetNumPlayers(NumberOfPlayers)!=1);


	Game::Get().getPlayers(0).SetNumPlayers(NumberOfPlayers);
	Game::Get().getPlayers(1).SetNumPlayers(NumberOfPlayers);
	for (int i = 0; i < NumberOfPlayers; i++)
	{
		int num = 0;
		cout << "\tPlease enter a prime Nnmber\n ";
		cin >> num;
		while (Game::Get().getPlayers(0).getPrimeNumber().CheckPrimeNumber(num) != 1)
		{
			cout << num << "\tIs not a prime Number ... Please enter a prime Number\n";
			cin >> num;
		}
		Game::Get().getPlayers(0).SetPlayers(num);
		int n= Game::Get().getPlayers(1).getPrimeNumber().RandomPrimeNumber(); // Generates a random number for the AI PLayer 
		Game::Get().getPlayers(1).SetPlayers(n);
	}

	system("CLS"); // This will clear the screen ready for the game to being !
}

void TwoPlayerGame()
{
	cout << "\t\tYou Selected A Two Player Game\n\n" << endl;
	
	string Temp,display;

	int NumberOfPlayers = 0, gameType = 0, NumGoals = 0, time = 0;
	for (int i = 0; i < 2; i++) {
		cout << "\t\tPlease enter Players " << i + 1 << " Name\n\n";
		cin >> Temp;
		Game::Get().getPlayers(i).SetTeamName(Temp);
	}

	do
	{
		display = "\tPlease enter the Number of Players on each team (Between 3 & 11): ";
		CheckVaildUserInput(display, NumberOfPlayers);

	} while (Game::Get().getPlayers(0).SetNumPlayers(NumberOfPlayers)!=1);

	Game::Get().getPlayers(0).SetNumPlayers(NumberOfPlayers); 
	Game::Get().getPlayers(1).SetNumPlayers(NumberOfPlayers);

	for (int i = 0; i < 2; i++) {

		cout << "\t\t" << Game::Get().getPlayers(i).GetTeamName() << " Select your Player Numbers\n\n";
		for (int j = 0; j < NumberOfPlayers; j++)
		{
			int num = 0;
			cout << " \t\tPlease enter player " << j + 1 << " number\n\n ";
			cin >> num;
			while (Game::Get().getPlayers(i).getPrimeNumber().CheckPrimeNumber(num) != 1)
			{
				cout << num << "\t\tIs not a prime Number ... Please enter a prime Number\n\n";
				cin >> num;
			}
			Game::Get().getPlayers(i).SetPlayers(num);
		}
	}

	system("CLS"); // This will clear the screen ready for the game to being !

	cout << "Please select a Game Type \n\t1:Number of Goals Game \n\t 2:Timed Game" << endl;
	cin >> gameType;
	if (gameType == 1)
	{
		cout << "\tYou selected Number Of Goals\n";
		do
		{
			display = "\t How many goals would you like to play to?";
			CheckVaildUserInput(display, NumGoals); 

		} while (Game::Get().set_goals_to_win(NumGoals) != 1);
		Game::Get().set_goals_to_win(NumGoals);
		Game::Get().set_time_to_win(-1);

	}
	else
	{
		cout << "\tYou selected a timed game\n";
		do
		{// Need to add in the error handling to check that its only numbers

			display = "\tHow long would you like the game to last?(mins):";
			CheckVaildUserInput(display, time);

		} while (Game::Get().set_time_to_win(time) != 1);
		Game::Get().set_time_to_win(time);
		Game::Get().set_goals_to_win(-1);
	}

	system("CLS");

	cout << "\t\t Coin toss!\n" << endl;
	bool result = Game::Get().coin_toss();

	if (result == 0) {
		cout << "Player 1 has won the coin toss" << endl;
	}
	else {
		cout << "Player 2 has won the coin toss" << endl;
		Game::Get().switch_possesion();
	}
;
	int count = 0;
	while (Game::Get().GameOver()) {
	START:
		
			int choice[2];
			cout << Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName() << " has possesion!" << endl << endl;
			cout << "You need to get past " << Game::Get().getPlayers(1).GetNumPlayers() - count << " players" << endl << endl;;
			Sleep(1);
			cout << "Press enter to roll the dice to tackle" << endl;
			cin.get();

			Dice::Get().diceroll();

			cout << "The dice rolled " << Dice::Get().getState() << endl << endl;

			for (int i = 0; i < 2; i++) {

				cout << Game::Get().getPlayers(i).GetTeamName() << " chose your player" << endl;
				for (int j = 0; j < Game::Get().getPlayers(i).GetNumPlayers(); j++) {
					cout << j + 1 << ": " << Game::Get().getPlayers(i).GetPlayers(j) << endl;
				}
				cin >> choice[i];
				choice[i]--;
			}

				cout << Game::Get().getPlayers(0).GetTeamName() << " has a remainder of " << Game::Get().get_remainder(0, choice[0]) << endl;
					cout << Game::Get().getPlayers(1).GetTeamName() << " has a remainder of " << Game::Get().get_remainder(1, choice[1]) <<endl ;

				if (Game::Get().tackle(choice[0], choice[1], Dice::Get().getIndex())) {

					cout << "Your tackle was sucessfull" << endl;
					count++;

				}
				else {
					cout << "Your tackle was unsucessfull and you have lost possesion" << endl;
					count = 0;
					Game::Get().switch_possesion();
				}

				if (count == Game::Get().getPlayers(1).GetNumPlayers()) {
					Game::Get().getPlayers(Game::Get().get_possesion()).SetGoals();
					count = 0;
					cout << Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName() << " has scored!" << endl << endl;
					Game::Get().switch_possesion();
					goto START;
					

			}

	}

		}

		