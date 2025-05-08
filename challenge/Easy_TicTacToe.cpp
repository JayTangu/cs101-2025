#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <conio.h>
using namespace std;

const char PLAYER1 = 'X';
const char COMPUTER = 'O';
const char PLAYER2 = 'O';

class TicTacToe{
	public:
	char board[3][3];
	char showboard[3][3];
	
	void resetBoard() {
	char* p = &board[0][0];
	char* sp = &showboard[0][0];
	for(int i = 0 ; i < 9 ; i++) {
		*(sp+i)=i+'1';
		*(p+i)= ' ';
		}
	}

void CoutBoard() {
	cout<<endl;
	printf(" %c | %c | %c ", showboard[0][0], showboard[0][1], showboard[0][2]);
	cout<<endl<<"---|---|---"<<endl;
	printf(" %c | %c | %c ", showboard[1][0], showboard[1][1], showboard[1][2]);
	cout<<endl<<"---|---|---"<<endl;
	printf(" %c | %c | %c ", showboard[2][0], showboard[2][1], showboard[2][2]);
	cout<<endl;
}

int NonSpacesIf() {
	int spaces = 9;
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < 3 ; j++)
			if(board[i][j]!=' ')
				spaces--;
	return spaces;
}

void player1Move(){
	int x;
	char* p = &board[0][0];
	char* sp = &showboard[0][0];
	do {
	cout<<"玩家1，輸入(1~9): "; 
	cin>>x;
	if(*(p+x-1) != ' ')
		cout<<"錯誤輸入，已經有人選擇這了！"<<endl;
	else {
         *(p+x-1) = PLAYER1;
         *(sp+x-1) = PLAYER1;
         p = &board[0][0];
         break;
	}
	} while(*(p+x-1)!=' ');
}

void player2Move() {
	int x;
	char* p = &board[0][0];
	char* sp = &showboard[0][0];
	do {
	cout<<"玩家2，輸入(1~9): "; 
	cin>>x;
	if(*(p+x-1) != ' ')
		cout<<"錯誤輸入，已經有人選擇這了！"<<endl;
	else {
         *(p+x-1) = PLAYER2;
         *(sp+x-1) = PLAYER2;
         p = &board[0][0];
         break;
	}
	} while(*(p+x-1)!=' ');
}

char checkWinner() {
	for(int i = 0 ; i < 3 ; i++)
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
			return board[i][0]; //回傳row(3)column(0)的"字元" 
			
	for(int i = 0 ; i < 3 ; i++)
		if(board[0][i]==board[1][i]&&board[0][i]==board[2][i])
			return board[0][i]; //回傳row(0)column(3)的"字元" 
			
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2])
		return board[0][0];
		
	if(board[0][2]==board[1][1]&&board[0][2]==board[2][0])
		return board[0][2];
		
	return ' ';
}

void CoutWinnerPVP(char winner) {
	if(winner==PLAYER1)
		cout<<endl<<"PLAYER 1 WIN";
	else if(winner==PLAYER2)
		cout<<endl<<"PLAYER 2 WIN";
	else
		cout<<endl<<"TIE";	
}
	char winner=' ';
	char response = ' '; //是否重複
	void startgame() {
		while(true) {
			winner=' ';
			response=' ';
			resetBoard();
		
			while(winner==' '&&NonSpacesIf()!=0) {
				CoutBoard();
				player1Move();
				winner=checkWinner();
				if(winner!=' '||NonSpacesIf()==0)
					break;
				CoutBoard();
				player2Move();
				winner=checkWinner();
				if(winner!=' '||NonSpacesIf()==0)			
					break;
			}
			CoutBoard();
			CoutWinnerPVP(winner);
		}
	}
};

int main()
{
	TicTacToe tictactoc;
	tictactoc.startgame();
	return 0;	
}   
