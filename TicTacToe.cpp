#include <iostream>
using namespace std;

int player = 2;
int space = 0;
int count = 0;
int move;
char playericon;
bool ifvalid = true;
bool winner = false;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void makemove(int move, char board[], char playericon, bool& ifvalid);
bool checkwinner(char board[9]);
void printboard(char board[9]);
int switchplayer(int player);

int main(){
	while(winner == false){
        count = count + 1;
		player = switchplayer(player);
		if(player == 1) {
			playericon = 'X';
		} else {
            playericon = 'O';
		}
		std::cout << "player " << playericon << ", make your move" << endl;
		std::cin >> move;

		makemove(move, board, playericon, ifvalid);

		while (ifvalid == false){
			std::cout << "invalid move, try again" << std::endl;
			ifvalid = true;
			std::cin >> move;
			makemove(move, board, playericon, ifvalid);
		}
		printboard(board);
		winner = checkwinner(board);
		if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9') {
			space = 1;
		}
		if(space == 1){
                winner = true;
        }
	}
    if(count == 9){
        std::cout << "the game was a draw";
    } else if(player == 1) {
        std::cout << "player X has won";
    }else if(player == 2) {
        std::cout << "player O has won";
    }
    return 0;
}

void makemove(int move, char board[], char playericon, bool& ifvalid) {
	switch(move) {
		case 1 :  if (board[0] == '1') {
					board[0] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 2 :  if (board[1] == '2') {
					board[1] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 3 :  if (board[2] == '3') {
					board[2] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 4 :  if (board[3] == '4') {
					board[3] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 5 :  if (board[4] == '5') {
					board[4] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 6 :  if (board[5] == '6') {
					board[5] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 7 :  if (board[6] == '7') {
					board[6] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 8 :  if (board[7] == '8') {
					board[7] = playericon;
					} else {
					ifvalid = false;
					}
					break;
		case 9 :  if (board[8] == '9') {
					board[8] = playericon;
					} else {
					ifvalid = false;
					}
					break;
					default: ifvalid = false;
	}
}
int switchplayer(int player) {
	if(player == 1) {
		return 2;
	} else {
		return 1;
	}
}
bool checkwinner(char board[9]) {

		for (int i=0;i<9;i=i+3)
		if (board[i]==board[i+1]&&board[i]==board[i+2]){
            return true;}
        for(int j=0;j<3;j++)
        if (board[j]==board[j+3]&&board[j]==board[j+6]){
            return true;}
        if (board[0]==board[4]&&board[0]==board[8])
            return true;
        if (board[2]==board[4]&&board[2]==board[6])
            return true;

        return false;
	}

void printboard(char board[9]) {
	std::cout << "   " << board[0] << "   " << " | ";
	std::cout << "   " << board[1] << "   " << " | ";
	std::cout << "   " << board[2] << "   " << endl;
	std::cout << "    __________________" << endl;
	std::cout << "   " << board[3] << "   " << " | ";
	std::cout << "   " << board[4] << "   " << " | ";
	std::cout << "   " << board[5] << "   " << endl;
	std::cout << "    __________________" << endl;
	std::cout << "   " << board[6] << "   " << " | ";
	std::cout << "   " << board[7] << "   " << " | ";
	std::cout << "   " << board[8] << "   " << endl;
	std::cout << "    __________________" << endl;
}
