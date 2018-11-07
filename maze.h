#ifndef _MAZE_H_
#define _MAZE_H_

#include <iostream>
#include "vector.h"

class maze
{
	enum { END = '!', SPACE = ' ', WALL = '#', PATH = '*', BACKTRACK = '.' };

	myVector::Vector<std::string> puzzle;

public:
	maze(myVector::Vector<std::string> p) : puzzle{ p } { }

	int solve(size_t row = 0, size_t column = 0)
	{
		if (row < 0 || column < 0 || row >= puzzle.size() || column >= puzzle[0].size())
			return false;

		if (puzzle[row][column] == END)
			return true;

		if (puzzle[row][column] != SPACE)
			return false;

		puzzle[row][column] = PATH;

		bool solved = solve(row - 1, column) || solve(row + 1, column) || solve(row, column - 1) || solve(row, column + 1);

		if (!solved)
			puzzle[row][column] = BACKTRACK;

		return solved;
	}

	friend std::ostream& operator<< (std::ostream& os, maze& m)
	{
		for (auto const &s : m.puzzle)
			os << s << '\n';
		return os;
	}
};
#endif 
