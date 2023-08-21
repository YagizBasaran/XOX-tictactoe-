//============================================================================
// Name        : XOX.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Board.h"
#include <iostream>
using namespace std;

int main() {
	cout << "If you want to play press 'y' else 'n' " << endl;
	string ans;
	cin >> ans;
	if(ans == "y"){
		string player1; string player2;
		cout << "To play; choose as pressing 'x' or 'o' " << endl;
		cin >> player1;
		if(player1 == "x"){
			player2 = "o";
		}
		else{

			player2 = "x";
			player1 = "o";
		}

		int gameOn = -1;
		cout << "Welcome to the game! \n" << endl;

		Board bd;
		bd.setBoard();
		bd.printBoard();

		int count = 0; bool canPlay;
		while(gameOn == -1){
			int row; int column;

			if(player1 == "x"){
				cout << endl;
				cout << "Player 1 plays (as 'x') firstly enter *row* then enter *column*: " << endl;
				cin >> row; cin >> column;
				canPlay = bd.updateBoard("x", row, column);
				while(!canPlay){
					cout << "Enter valid row and column pls:" << endl;
					cin >> row; cin >> column;
					canPlay = bd.updateBoard("x", row, column);
				}
				count++;
				gameOn = bd.didWin(count);
				bd.printBoard();
				if(gameOn != -1) break;

				//cout << "gameOn = " << gameOn << endl;

				cout << endl;
				cout << "Player 2 plays (as 'o') firstly enter *row* then enter *column*: " << endl;
				cin >> row; cin >> column;
				canPlay = bd.updateBoard("o", row, column);
				while(!canPlay){
					cout << "Enter valid row and column pls:" << endl;
					cin >> row; cin >> column;
					canPlay = bd.updateBoard("o", row, column);
				}
				count++;
				gameOn = bd.didWin(count);
				bd.printBoard();
				if(gameOn != -1) break;

				//cout << "gameOn = " << gameOn << endl;

			}
			else{
				cout << endl;
				cout << "Player 1 plays (as 'o') firstly enter *row* then enter *column*: " << endl;
				cin >> row; cin >> column;
				canPlay = bd.updateBoard("o", row, column);
				while(!canPlay){
					cout << "Enter valid row and column pls:" << endl;
					cin >> row; cin >> column;
					canPlay = bd.updateBoard("o", row, column);
				}
				count++;
				gameOn = bd.didWin(count);
				bd.printBoard();
				if(gameOn != -1) break;

				cout << endl;
				cout << "Player 2 plays (as 'x') firstly enter *row* then enter *column*: " << endl;
				cin >> row; cin >> column;
				canPlay = bd.updateBoard("x", row, column);
				while(!canPlay){
					cout << "Enter valid row and column pls:" << endl;
					cin >> row; cin >> column;
					canPlay = bd.updateBoard("x", row, column);
				}
				count++;
				gameOn = bd.didWin(count);
				bd.printBoard();
				if(gameOn != -1) break;

			}
		}

		if(gameOn == 0) cout << "Draw, unlucky." << endl;
		else if(gameOn == 1) cout << "Player 1 wins, congrats!" << endl;
		else if(gameOn == 2) cout << "Player 2 wins, congrats!" << endl;

	}
	else
		cout << "Bye Bye";
	return 0;
}
