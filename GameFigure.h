#ifndef GAME_FIGURES_H
#define GAME_FIGURES_H

enum GameFigures {
	rock = 0,
	paper,
	scissor
};

struct GameFigure {

public:
	virtual ~GameFigure() { }

	virtual GameFigures getType() const = 0;
};

class Rock : public GameFigure {

public:
	
	GameFigures getType() const override {
		return GameFigures::rock;
	}
};

class Paper : public GameFigure {

public:
	GameFigures getType() const override {
		return GameFigures::paper;
	}
};

class Scissor : public GameFigure {

public:
	GameFigures getType() const override {
		return GameFigures::scissor;
	}
};


// ==========================================================================

inline bool operator==(GameFigure& lhs, GameFigure& rhs) {

	return (lhs.getType() == rhs.getType());
}

inline bool operator< (GameFigure& lhs, GameFigure& rhs) {
	
	if (lhs.getType() == GameFigures::rock) {

		if (rhs.getType() == GameFigures::paper)
			return false;

		return true;
	}

	if (lhs.getType() == GameFigures::paper) {

		if (rhs.getType() == GameFigures::rock)
			return true;

		return false;
	}

	if (lhs.getType() == GameFigures::scissor) {

		if (rhs.getType() == GameFigures::paper)
			return true;

		return false;
	}
}

#endif // !GAME_FIGURES_H