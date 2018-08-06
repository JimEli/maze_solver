#include <iostream>
#include <string>
#include <vector>

#include "maze.h"

int main()
{
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
