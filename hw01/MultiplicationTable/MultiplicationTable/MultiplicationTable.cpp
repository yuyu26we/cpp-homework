#include <iostream>

const int mTableRows = 8;
const int mTableCols = 8;

int main()
{
	int multiplicationTable[mTableRows][mTableCols];
	int firstNum = 0;
	int secondNum = 0;

	for (int i = 0; i < mTableRows; i++)
		for (int j = 0; j < mTableCols; j++)
			multiplicationTable[i][j] = (i + 2) * (j + 2);

	/*for (int i = 0; i < mTableRows; i++) {
		for (int j = 0; j < mTableCols; j++)
		{
			std::cout << multiplicationTable[i][j] << '\t' << ' ';
		}
		std::cout << '\n';
	}*/

	//comment

	std::cout << "Write 1st num: ";
	std::cin >> firstNum;

	std::cout << "Write 2st num: ";
	std::cin >> secondNum;

	std::cout << "Result: " << multiplicationTable[firstNum - 2][secondNum - 2];
}
