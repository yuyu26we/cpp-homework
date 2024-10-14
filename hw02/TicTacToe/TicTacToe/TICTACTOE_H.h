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
void DrawGrid(int grid[][3], int gridSize); //������������ ������� ����

void SetupPlayers(string players[]); //������� �������

int ChooseLuckyOne(); //�������� ��� ����� ������ ������ 

//������ ��� ������ ��� �������� playerThatMovesIndex, ���� ��� players[playerThatMovesIndex] - "bot", �� ������������ ������ ����
void MakeMove(int grid[][3], int gridSize, string players[], int playerThatMovesIndex, int goesFirst); 

//������ ������ ����
void BotMove(int grid[][3], int gridSize, string players[], int playerThatMovesIndex, int goesFirst);

//������ ����
void StartGame(int grid[][3], int gridSize, string players[]);

//���������� ���������� �������� ����
void ResetGame(int grid[][3], int gridSize, string players[]);

//���������� ��������� ���� �� ������ ������
GameStatement CheckGameStatement(int grid[][3], int gridSize);

//���������� ����������������� ��������� ��� ������ �� string, � ��������� Turn
Turn ConvertTurn(string turn);
