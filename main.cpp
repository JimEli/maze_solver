// 269 - Homework 6 - Recursion.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string>
#include <vector>

#include "counting.h"
#include "maze.h"

int main()
{
	//the number used to count to and from
	int N = 11;

	std::cout << "Count Up: ";
	CountUp(&N);

	std::cout << "\nCount Up: ";
	printUp(N);

	std::cout << "\nCount Down: ";
	countDown(N);

	std::cout << "\nCount Down: ";
	countDown(&N);

	std::cout << "\nCount Down Odd: ";
	countDownOdd(N);

	std::cout << "\nCount Up: ";
	countUp(11);
	std::cout << "\nCount Up: ";
	char a = '\n' + 1; countUp(a);
	std::cout << "\nCount Up: ";
	countUp(11.3);
	std::cout << "\nCount Up: ";
	countUp("abc");

	//
	//
	//
	std::vector<std::string> puzzle;

	puzzle.push_back("  #######");
	puzzle.push_back("#    # ##");
	puzzle.push_back("# ####  #");
	puzzle.push_back("#      ##");
	puzzle.push_back("# ### ###");
	puzzle.push_back("#####  !#");

	maze m = maze(puzzle);

	std::cout << std::endl;

	if (m.solve())
		std::cout << m;
	else
		std::cout << "Could not solve maze!\n";
	return 0;
}
