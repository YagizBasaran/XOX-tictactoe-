
#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
using namespace std;

class Board{

public:

	Board();
	~Board();

	void printBoard();
	bool updateBoard(string XO, int row, int column);
	void setBoard();
	int didWin(int count);

	string board[3][3];

};




#endif /* BOARD_H_ */
