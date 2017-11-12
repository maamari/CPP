/* 
mazeio.cpp

Author: Karime Maamari

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"

using namespace std;

char** read_maze(int* rows, int* cols) {

	char** maze = new char* [*rows];		//make rows

	for(int r = 0; r < *rows; r++){			//make cols
		maze[r] = new char[*cols];
	}

	for(int r = 0; r < *rows; r++){
		for(int c = 0; c < *cols; c++){
			cin >> maze[r][c];				//cin maze to program
		}
	}

	return maze;
}

void print_maze(char** maze, int rows, int cols) {

	cout << rows << " " << cols << endl;	//rows cols

	for(int r = 0; r < rows; r++){			//output maze to user
		for(int c = 0; c < cols; c++){
			cout << maze[r][c];
		}
		cout << endl;
	}
}

