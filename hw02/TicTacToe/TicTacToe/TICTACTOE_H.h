#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//enums
enum class GameStatement {Draw, Win, InProgress};
enum class Side {Empty, Cross, Circle};

//structs
struct Turn
{
	int x = 0;
	int y = 0;
};

//tictactoe funcs
void DrawGrid(int grid[][3], int gridSize); //Отрисовывает игровое поле

void SetupPlayers(string players[]); //Именует игроков

int ChooseLuckyOne(); //Выбирает кто будет ходить первым 

//Делает ход игрока под индексом playerThatMovesIndex, если под players[playerThatMovesIndex] - "bot", то отрабатывает логика бота
void MakeMove(int grid[][3], int gridSize, string players[], int playerThatMovesIndex, int goesFirst); 

//Логика ходьбы бота
void BotMove(int grid[][3], int gridSize, string players[], int playerThatMovesIndex, int goesFirst);

//Запуск игры
void StartGame(int grid[][3], int gridSize, string players[]);

//Сбрасывает переменные игрового поля
void ResetGame(int grid[][3], int gridSize, string players[]);

//Возвращает состояние игры на момент вызова
GameStatement CheckGameStatement(int grid[][3], int gridSize);

//Возвращает сконвертированный введенный ход игрока из string, в структуру Turn
Turn ConvertTurn(string turn);
