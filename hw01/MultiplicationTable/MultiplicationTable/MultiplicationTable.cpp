﻿#include <iostream>

int main()
{
	const int TABLESIZE = 9;

	int multiplicationTable[TABLESIZE][TABLESIZE];
	int firstNum = 0;
	int secondNum = 0;

	for (int i = 0; i < TABLESIZE; i++) {
		for (int j = 0; j < TABLESIZE; j++)
		{
			multiplicationTable[i][j] = (i + 1) * (j + 1);
			std::cout << multiplicationTable[i][j] << '\t' << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Write 1st num: ";
		std::cin >> firstNum;

		std::cout << "Write 2st num: ";
		std::cin >> secondNum;

		std::cout << std::endl;

		if (firstNum == 0 || secondNum == 0)
		{
			std::cout << "Program closed" << std::endl;
			break;
		}
		if ((firstNum < 0 || firstNum > TABLESIZE) || (secondNum < 0 || secondNum > TABLESIZE))
		{
			std::cout << "Count by yourself \n" << std::endl;
			continue;
		}

		std::cout << "Result: " << multiplicationTable[firstNum - 1][secondNum - 1] << "\n" << std::endl;
	} 
}
	