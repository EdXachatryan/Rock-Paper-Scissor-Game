#include "GameManager.h"

GameManager::GameManager() {

	std::cout << "Type Player1 name : ";
	std::cin >> player1Name;
	NEWLINE;
	std::cout << "Type Player2 name : ";
	std::cin >> player2Name;
	NEWLINE;
}

GameManager::~GameManager() {
	std::cout << "End the game...";
}

void GameManager::play(std::unique_ptr<GameFigure> lhs, std::unique_ptr<GameFigure> rhs) {

	int resutl = findWinner(*lhs.get(), *rhs.get());

	switch (resutl)
	{
	case 0: {
		std::cout << "Draw";
		break;
	}
	case -1: {
		std::cout << player1Name << " wins ";
		break;
	}
	case 1: {
		std::cout << player2Name << " wins ";
		break;
	}

	default:
		break;
	}
	NEWLINE;
}

void GameManager::play() {

	char quit = 'y';

	while (quit != 'q') {

		CLRSCREEN;

		auto fig1 = getFigure(true);
		auto fig2 = getFigure(false);
		play(std::move(fig1), std::move(fig2));

		std::cout << "For quit press  ' q '";
		std::cin >> quit;
	}
}

int GameManager::findWinner(GameFigure& lhs, GameFigure& rhs) {

	if (lhs == rhs)
		return 0;

	return (lhs < rhs) ? -1 : 1;
}

std::unique_ptr<GameFigure> GameManager::getFigure(bool player1) {
	
	NEWLINE;
	std::cout << "Choose a figure:  S : scissor |  R : rock  | P : paper ";
	NEWLINE;
	std::string player = (player1) ? player1Name : player2Name;
	std::cout << player << " input : ";
	char ch;
	std::cin >> ch;

	switch (ch)
	{

	case 's':
	case 'S': {
		return std::make_unique<Scissor>();
	}

	case 'p':
	case 'P': {
		return std::make_unique<Paper>();
	}

	case 'r':
	case 'R': {
		return std::make_unique<Rock>();
	}

	default:
		std::cout << "Forbited symbol, Choose a figure:  S : scissor |  R : rock  | P : paper ";
		return getFigure(player1);
		break;
	}
}