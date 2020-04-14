#include "Error_Handeling.h"
#include <iostream>

bool set_if_valid_number(string n, int& target)
{
	for (int i = 0; i < n.length(); i++) 
	{
		if (n[i] < '0' && n[i] > '9') 
		{  
			return false;
		}
		else
		{
			target = stoi(n);
			return true;
		}

	}
}
	
void CheckVaildUserInput(string display ,int& target)
{
	string temp;
	cout << display;
	cin >> temp;

	try
	{
		(set_if_valid_number(temp, target)); // Checks to see if user has entered a vaid input

	}
	catch (const std::exception&)
	{
		cout << "you did not enter only numbers\n";

	}

}

