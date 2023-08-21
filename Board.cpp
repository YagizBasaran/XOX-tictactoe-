#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(){};
Board::~Board(){};

void Board::setBoard(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = " ";
		}
	}
}

void Board::printBoard(){

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << "|" + board[i][j] + "|";
		}
		cout << endl;
	}
}

bool Board::updateBoard(string XO, int row, int column){

	bool canPlay;

	if(board[row-1][column-1] == " "){
		board[row-1][column-1] = XO;
		canPlay = true;}
	else{
		cout<<"You can't select the occupied square."<<endl;
		canPlay = false;}

	return canPlay;

}

int Board::didWin(int count){// -1 = continue, 0 = draw, 1 = player1 wins, 2 = player2 wins

	int result = -1;

	//lateral condition
	if((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
	   (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
	   (board[2][0] == board[2][1] && board[2][1] == board[2][2])){

			if(board[0][0] == "x" && board[0][1] == "x" && board[0][2] == "x"){ result = 1;}
			else if(board[0][0] == "o" && board[0][1] == "o" && board[0][2] == "o"){ result = 2; }

			if(board[1][0] == "x" && board[1][1] == "x" && board[1][2] == "x"){ result = 1; }
			else if(board[1][0] == "o" && board[1][1] == "o" && board[1][2] == "o"){ result = 2; }

			if(board[2][0] == "x" && board[2][1] == "x" && board[2][2] == "x"){ result = 1; }
			else if(board[2][0] == "o" && board[2][1] == "o" && board[2][2] == "o"){ result = 2; }
	}

	//horizontal condition
	if((board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
	   (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
	   (board[0][2] == board[1][2] && board[1][2] == board[2][2])){

		if(board[0][0] == "x" && board[1][0] == "x" && board[2][0] == "x"){ result = 1; }
		else if(board[0][0] == "o" && board[1][0] == "o" && board[2][0] == "o"){ result = 2;}

		if(board[0][1] == "x" && board[1][1] == "x" && board[2][1] == "x"){ result = 1;}
		else if(board[0][1] == "o" && board[1][1] == "o" && board[2][1] == "o"){ result = 2;}

		if(board[0][2] == "x" && board[1][2] == "x" && board[2][2] == "x"){ result = 1;}
		else if(board[0][2] == "o" && board[1][2] == "o" && board[2][2] == "o"){ result = 2;}
	}

	//diagonal condition
	if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
	   (board[0][2] == board[1][1] && board[1][1] == board[2][0])){

		if(board[0][0] == "x" && board[1][1] == "x" && board[2][2] == "x") result = 1;
		else if(board[0][0] == "o" && board[1][1] == "o" && board[2][2] == "o") result = 2;

		if(board[0][2] == "x" && board[1][1] == "x" && board[2][0] == "x") result = 1;
		else if(board[0][2] == "o" && board[1][1] == "o" && board[2][0] == "o") result = 2;

	}

	//draw
	if(count == 9) result = 0;


	return result;
}



