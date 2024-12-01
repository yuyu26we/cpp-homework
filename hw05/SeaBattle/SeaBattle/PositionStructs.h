#pragma once
#include <ostream>

struct Position
{
	int x;
	int y;

	Position() : x(0), y(0) {}
	Position(int x, int y) : x(x), y(y) {}

	bool operator==(Position & otherPos)
	{
		return x == otherPos.x && y == otherPos.y;
	}
};

struct ShipPartPosition : Position
{
	ShipPartPosition() : Position() {}
	ShipPartPosition(int x, int y) : Position(x, y) {}
	bool isHitted = false;
};

