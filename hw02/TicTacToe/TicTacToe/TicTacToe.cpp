#include "TICTACTOE_H.h"

void DrawGrid(int grid[][3], int gridSize)
{
	cout << "    A | B | C " << endl;
	cout << "  -------------" << endl;
	for (int i = 0; i < gridSize; i++)
	{
		cout << i + 1 << " | ";
		for (int j = 0; j < gridSize; j++)
		{
			char symbol = ' ';
			switch ((Side)grid[i][j])
			{
			case Side::Cross:
				symbol = 'x';
				break;
			case Side::Circle:
				symbol = 'o';
				break;
			}
			cout << symbol << " | ";
		}
		cout << "\n- -------------" << endl;
	}

	cout << endl;
}

void SetupPlayers(string players[])
{
	string answer = "";

	for (int i = 0; i < 2; i++)
	{
		cout << i + 1 << " player is (bot/player): ";
		cin >> answer;
		cout << endl;

		while (answer != "player" && answer != "bot")
		{
			cout << "Incorrect input!" << endl;
			cout << i + 1 << " player is (bot/player): ";
			cin >> answer;
			cout << endl;
		}

		if (answer == "player")
		{
			string playerName;

			cout << "Name min length = 3 and not \"bot\"" << endl;
			cout << i + 1 << " player name: ";
			cin >> playerName;
			cout << endl;

			while (playerName.length() < 3 || playerName.substr(0, 3) == "bot")
			{
				cout << "Incorrect name!" << endl;
				cout << "Name min length = 3 and not \"bot\"" << endl;
				cout << i + 1 << " player name: ";
				cin >> playerName;
				cout << endl;
			}

			players[i] = playerName;

			if (i == 0) players[1] = "bot";
			else if (i == 1 && players[0].substr(0, 3) == "bot")
			{
				players[0] = "bot";
			}
		}
	}
}

int ChooseLuckyOne()
{
	srand(time(NULL));
	return 0 + rand() % 2;
}

void MakeMove(int grid[][3], int gridSize, string players[], int playerThatMovesIndex, int goesFirst)
{
	string playerName = players[playerThatMovesIndex];
	int codedPlayerSide = (playerThatMovesIndex == goesFirst) ? 1 : 2;

	cout << playerName << "'s" << " turn." << endl;
	cout << endl;

	//Логика хода игрока
	if (playerName.substr(0, 3) != "bot")
	{
		string turn = "";
		Turn convertedTurn;

		cout << "Write turn (format - A1): ";
		cin >> turn;
		cout << endl;

		convertedTurn = ConvertTurn(turn);

		while (grid[convertedTurn.x][convertedTurn.y] != 0 || (convertedTurn.x < 0 || convertedTurn.x > 2) || (convertedTurn.y < 0 || convertedTurn.y > 2))
		{
			if ((convertedTurn.x < 0 || convertedTurn.x > 2) || (convertedTurn.y < 0 || convertedTurn.y > 2))
			{
				cout << "Incorrect slot, choose another one (format - A1): ";
			}
			else { cout << "This slot is busy, choose another one (format - A1): "; }

			cin >> turn;
			cout << endl;

			convertedTurn = ConvertTurn(turn);
		}

		grid[convertedTurn.x][convertedTurn.y] = codedPlayerSide;
	}


	//Логика хода бота
	else { BotMove(grid, gridSize, players, playerThatMovesIndex, goesFirst); }
}

void StartGame(int grid[][3], int gridSize, string players[])
{
	bool isGameInProgress = true;
	while (isGameInProgress)
	{
		SetupPlayers(players);
		int goesFirst = ChooseLuckyOne();
		int i = goesFirst;

		cout << "first is: " << players[goesFirst] << "!\n" << endl;
		DrawGrid(grid, gridSize);

		bool isRoundInProgress = true;
		while (isRoundInProgress)
		{
			MakeMove(grid, gridSize, players, i, goesFirst);

			DrawGrid(grid, gridSize);

			switch (CheckGameStatement(grid, gridSize))
			{
			case GameStatement::Win:
				cout << "Winner is " << players[i] << "!" << endl;
				isRoundInProgress = false;
				break;
			case GameStatement::Draw:
				cout << "Draw!" << endl;
				isRoundInProgress = false;
				break;
			}

			i = (i == 0) ? 1 : 0;
		}

		string answer;
		cout << "Wanna play more? (yes/no):";
		cin >> answer;
		cout << endl;

		while (answer != "yes" && answer != "no")
		{
			cout << "Incorrect input!" << endl;
			cout << "Wanna play more? (yes/no): ";
			cin >> answer;
			cout << endl;
		}

		if (answer == "yes") { ResetGame(grid, gridSize, players); }
		else { isGameInProgress = false; }
	}
}

void ResetGame(int grid[][3], int gridSize, string players[])
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			grid[i][j] = 0;
		}
	}

	players[0] = "bot1";
	players[1] = "bot2";
}

void BotMove(int grid[][3], int gridSize, string players[], int playerThatMovesIndex, int goesFirst) 
{
	int codedEnemySide = (playerThatMovesIndex == goesFirst) ? 2 : 1;
	int codedPlayerSide = (playerThatMovesIndex == goesFirst) ? 1 : 2;

	int countOfEnemyStreak = 0;
	int countOfBotStreak = 0;
	int indexOfEmptySlotToTurn = -1;

	Turn coordsOfBestTurn;
	bool isBestTurnFound = false;

	//Определение шага победы/защиты для горизонталей
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (grid[i][j] == codedEnemySide) { countOfEnemyStreak++; }
			else if (grid[i][j] == codedPlayerSide) { countOfBotStreak++; }
			else if (grid[i][j] == 0) { indexOfEmptySlotToTurn = j; }
		}

		if (countOfEnemyStreak == 2 && indexOfEmptySlotToTurn != -1 || countOfBotStreak == 2 && indexOfEmptySlotToTurn != -1)
		{
			isBestTurnFound = true;
			coordsOfBestTurn.x = i;
			coordsOfBestTurn.y = indexOfEmptySlotToTurn;

			if (countOfBotStreak == 2)
			{
				grid[coordsOfBestTurn.x][coordsOfBestTurn.y] = codedPlayerSide;
				return;
			}
		}

		countOfEnemyStreak = 0;
		countOfBotStreak = 0;
		indexOfEmptySlotToTurn = -1;
	}

	//Определение шага победы/защиты для вертикалей
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (grid[j][i] == codedEnemySide) { countOfEnemyStreak++; }
			else if (grid[j][i] == codedPlayerSide) { countOfBotStreak++; }
			else if (grid[j][i] == 0) { indexOfEmptySlotToTurn = j; }
		}

		if (countOfEnemyStreak == 2 && indexOfEmptySlotToTurn != -1 || countOfBotStreak == 2 && indexOfEmptySlotToTurn != -1)
		{
			isBestTurnFound = true;
			coordsOfBestTurn.x = indexOfEmptySlotToTurn;
			coordsOfBestTurn.y = i;

			if (countOfBotStreak == 2)
			{
				grid[coordsOfBestTurn.x][coordsOfBestTurn.y] = codedPlayerSide;
				return;
			}
		}

		countOfEnemyStreak = 0;
		countOfBotStreak = 0;
		indexOfEmptySlotToTurn = -1;
	}

	//Определение шага победы/защиты для 1 диагонали
	for (int i = 0; i < gridSize; i++)
	{
		if (grid[i][i] == codedEnemySide) { countOfEnemyStreak++; }
		else if (grid[i][i] == codedPlayerSide) { countOfBotStreak++; }
		else if (grid[i][i] == 0) { indexOfEmptySlotToTurn = i; }
	}

	if (countOfEnemyStreak == 2 && indexOfEmptySlotToTurn != -1 || countOfBotStreak == 2 && indexOfEmptySlotToTurn != -1)
	{
		isBestTurnFound = true;
		coordsOfBestTurn.x = indexOfEmptySlotToTurn;
		coordsOfBestTurn.y = indexOfEmptySlotToTurn;

		if (countOfBotStreak == 2)
		{
			cout << coordsOfBestTurn.x << " " << coordsOfBestTurn.y << endl;
			grid[coordsOfBestTurn.x][coordsOfBestTurn.y] = codedPlayerSide;
			return;
		}
	}

	countOfEnemyStreak = 0;
	countOfBotStreak = 0;
	indexOfEmptySlotToTurn = -1;

	//Определение шага победы/защиты для 2 диагонали
	for (int i = 0; i < gridSize; i++)
	{
		if (grid[gridSize - i - 1][gridSize - i - 1] == codedEnemySide) { countOfEnemyStreak++; }
		else if (grid[gridSize - i - 1][gridSize - i - 1] == codedPlayerSide) { countOfBotStreak++; }
		else if (grid[gridSize - i - 1][gridSize - i - 1] == 0) { indexOfEmptySlotToTurn = i; }
	}

	if (countOfEnemyStreak == 2 && indexOfEmptySlotToTurn != -1 || countOfBotStreak == 2 && indexOfEmptySlotToTurn != -1)
	{
		isBestTurnFound = true;
		coordsOfBestTurn.x = indexOfEmptySlotToTurn;
		coordsOfBestTurn.y = indexOfEmptySlotToTurn;

		if (countOfBotStreak == 2)
		{
			cout << coordsOfBestTurn.x << " " << coordsOfBestTurn.y << endl;
			grid[coordsOfBestTurn.x][coordsOfBestTurn.y] = codedPlayerSide;
			return;
		}
	}

	countOfEnemyStreak = 0;
	countOfBotStreak = 0;
	indexOfEmptySlotToTurn = -1;

	//Определение оптимального хода если нет возможности выиграть и не нужно защищаться
	if (!isBestTurnFound)
	{
		//Попытаться занять центр
		if (grid[1][1] == 0) { coordsOfBestTurn.x = 1; coordsOfBestTurn.y = 1; }

		//Попытаться занять один из углов
		else if (grid[0][0] == 0) { coordsOfBestTurn.x = 0; coordsOfBestTurn.y = 0; }
		else if (grid[2][0] == 0) { coordsOfBestTurn.x = 2; coordsOfBestTurn.y = 0; }
		else if (grid[0][2] == 0) { coordsOfBestTurn.x = 0; coordsOfBestTurn.y = 2; }
		else if (grid[2][2] == 0) { coordsOfBestTurn.x = 2; coordsOfBestTurn.y = 2; }

		//Попытаться занять один из боковых центров
		else if (grid[0][1] == 0) { coordsOfBestTurn.x = 0; coordsOfBestTurn.y = 1; }
		else if (grid[1][0] == 0) { coordsOfBestTurn.x = 1; coordsOfBestTurn.y = 0; }
		else if (grid[1][2] == 0) { coordsOfBestTurn.x = 1; coordsOfBestTurn.y = 2; }
		else if (grid[2][1] == 0) { coordsOfBestTurn.x = 2; coordsOfBestTurn.y = 1; }
	}

	grid[coordsOfBestTurn.x][coordsOfBestTurn.y] = codedPlayerSide;
}

GameStatement CheckGameStatement(int grid[][3], int gridSize)
{
	GameStatement gameStatement = GameStatement::Draw;
	for (int i = 0; i < gridSize; i++)
	{
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[2][i] != 0) { gameStatement = GameStatement::Win; }
		else if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][2] != 0) { gameStatement = GameStatement::Win; }
	}

	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != 0) { gameStatement = GameStatement::Win; }
	else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 0) { gameStatement = GameStatement::Win; }

	if (gameStatement == GameStatement::Draw)
	{
		for (int i = 0; i < gridSize; i++)
		{
			for (int j = 0; j < gridSize; j++)
			{
				if (grid[i][j] == 0)
				{
					gameStatement = GameStatement::InProgress;
					break;
				}
			}
			if (gameStatement == GameStatement::InProgress) break;
		}
	}

	return gameStatement;
}

Turn ConvertTurn(string turn)
{
	Turn convertedTurn;
	convertedTurn.x = turn[1] - '0' - 1;
	convertedTurn.y = toupper(turn[0]) - 'A';

	return convertedTurn;
}

