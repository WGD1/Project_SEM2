#include "Game.h"

Game& Game::Get()
{
	return Instance;
}

Game Game::Instance;

void Game::timer()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Game::time++;
}

bool Game::coin_toss() {
	return Randomiser(0, 1);
}

void Game::switch_possesion()
{
	Game::possesion = !Game::possesion;
}

int Game::get_remainder(bool player, int choice)
{
	return Game::getPlayers(player).GetPlayers(choice)% Dice::Get().getDividor();
}

bool Game::tackle(int p1, int p2, int diceroll)
{
	bool attacker, defender;
	switch (Game::possesion) {
		
	case 0:
		 attacker = 0;
		 defender = 1;
		break;
	case 1:
		 attacker = 1;
		 defender = 0;
		swap(p1, p2);

	}
	
	if (diceroll < 4) {
		if (Game::get_remainder(attacker,p1) >= Game::get_remainder(defender, p2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else  {
		if (Game::get_remainder(attacker, p1) <= Game::get_remainder(defender, p2)) {
			return true;
		}
		else {
			return false;
		}

	}
	
}

void Game::set_time_to_win(int num)
{
	Game::time_to_win = (num * 60);
}

void Game::set_goals_to_win(int num)
{
	Game::goals_to_win = num;
}

void Game::set_game_mode(bool mode)
{
	Game::game_mode = mode;
}

void Game::set_win_condition(bool condition)
{
	Game::win_condition = condition;
}

Team& Game::getPlayers(int i)
{
	return Game::Players[i];
}

int Game::get_time_to_win()
{
	return Game::time_to_win;
}

int Game::get_goals_to_win()
{
	return Game::goals_to_win;
}
bool Game::get_possesion()
{
	return Game::possesion;
}

bool Game::GameOver()
{
		if (Game::goals_to_win == Game::Players[0].GetGoals())
		{
			return false;
		}
		else if (Game::goals_to_win == Game::Players[1].GetGoals())
		{
			return false;
		}
	

	else if (Game::time == Game::time_to_win) {
		return false;
	}
	else {
			return true;
	}
}

