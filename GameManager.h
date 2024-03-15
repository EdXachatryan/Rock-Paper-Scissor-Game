#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <string>
#include "GameFigure.h"
#include <iostream>

#define NEWLINE std::cout << "\n";
#define CLRSCREEN system("CLS");

class GameManager {

public:
	GameManager();
	~GameManager();
	void play(std::unique_ptr<GameFigure> lhs, std::unique_ptr<GameFigure> rhs);
	void play();

private:
	int findWinner(GameFigure& lhs, GameFigure& rhs);
	std::unique_ptr<GameFigure> getFigure(bool player1);

private:
	std::string player1Name;
	std::string player2Name;
};

#endif // !GAME_MANAGER_H