#include "TICTACTOE_H.h"

int main()
{
	const int gridSize = 3;
	int playGrid[gridSize][gridSize] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	string players[2] = {"bot1", "bot2"};

	StartGame(playGrid, gridSize, players);
}