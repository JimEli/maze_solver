#pragma once

#ifndef _MAZE_H_
#define _MAZE_H_

#include <iostream>
#include <vector>

class maze
{
	enum { START = 'e', END = '!', SPACE = ' ', WALL = '#', PATH = '*', BACKTRACK = '.' };

	std::vector<std::string> puzzle;

public:
	maze(std::vector<std::string> p) : puzzle{ p } { }

	int solve(size_t column = 0, size_t row = 0)
	{
		if (column < 0 || row < 0 || row >= puzzle[0].size() || column >= puzzle.size())
			return false;

		if (puzzle[column][row] == END)
			return true;

		if (puzzle[column][row] != SPACE)
			return false;

		puzzle[column][row] = PATH;

		bool solved = solve(column, row - 1) || solve(column, row + 1) || solve(column - 1, row) || solve(column + 1, row);
		
		if (!solved)
			puzzle[column][row] = BACKTRACK;
		
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
