#include "Prime_Number.h" 
#include <iostream>
#include "Dice.h"
#include <windows.h>
#include <iostream>
#include "Interface.h"
#include "Game.h"
#include <cwchar>

using namespace std;



int main() 
{
	
	DrawHeader();
	int choice;//
	DrawMenu(180, '*');
	cout << "Please select an option:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		OnePlayerGame();
		break;
	}
	case 2:
		TwoPlayerGame();
		break;
	case 3:
		cout << "You selected choice 3" << endl;
		return 0;
		break;
	default:
		break;
	}
}





