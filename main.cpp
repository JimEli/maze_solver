#include <iostream>
#include <string>
#include "vector.h"
#include "maze.h"

// Visual Leak Detector.
#include "C:\Program Files (x86)\Visual Leak Detector\include\vld.h"

int main()
{
	myVector::Vector<std::string> puzzle;

	puzzle.push_back("  #######");
	puzzle.push_back("#    # ##");
	puzzle.push_back("# ####  #");
	puzzle.push_back("#      ##");
	puzzle.push_back("# ### ###");
	puzzle.push_back("#       #");
	puzzle.push_back("#######!#");

	maze m = maze(puzzle);

	std::cout << std::endl;

	if (m.solve())
		std::cout << m;
	else
		std::cout << "Could not solve maze!\n";
	return 0;
}
