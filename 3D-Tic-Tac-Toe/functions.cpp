#include <iostream>

using namespace std;
extern bool TRUE;
extern bool FALSE;
extern bool startGame;

void greetAndInstruct() {
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl << "The board is numbered from 1 to 27 as per the following: \n";
    string a = "----- \t -------- \t -------- \n";
    cout << "1|2|3 \t 10|11|12 \t 19|20|21" << endl;
    cout << a;
    cout << "4|5|6 \t 13|14|15 \t 22|23|24" << endl;
    cout << a;
    cout << "7|8|9 \t 16|17|18 \t 25|26|27" << endl;
    
    cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O. \n";
    
    cout<< "Start?(y/n): \t";
    // char var;
    // cin >> var;
    string var;
    getline(cin, var);
   
    // loop until get y or n as answer
    while(var != "") {
       if(var == "y") {
            startGame = TRUE;
            break;
        }
        else if(var == "n") {
            break;
        }
        else {
            cout << "Please type 'y' or 'n': \t";
            cin >> var;
        } 
    }
    
}

void displayBoard(char board[]) {
    // first lines of three boards
    for(int i=0; i< 27; i++){
        if(i < 3 || (i > 8 && i < 12) || (i > 17 && i < 21)) {
            if(i%3 != 2) {
                if(board[i] != 0) {
                    cout << board[i] << "|";
                }
                else {
                    cout << i+1 << "|";
                }
            }
            else if(i == 20) {
                if(board[i] != 0){
                    cout << board[i] << "|" << endl;
                }
                else {
                    cout << i+1 << "|" << endl;
                }
            }
            else {
                if(board[i] != 0){
                    cout << board[i] << "| \t";
                }
                else {
                    cout << i+1 << "| \t";
                }
            }
        }
    }  
    
    cout << "------\t---------\t--------- \n";
    
    // second line of three boards
    for(int i=0; i< 27; i++){
        if( (i > 2 && i < 6) || (i > 11 && i < 15) || (i > 20 && i < 24)) {
            if(i%3 != 2) {
                if(board[i] != 0) {
                    cout << board[i] << "|";
                }
                else {
                    cout << i+1 << "|";
                }
            }
            else if(i == 23) {
                if(board[i] != 0){
                    cout << board[i] << "|" << endl;
                }
                else {
                    cout << i+1 << "|" << endl;
                }
            }
            else {
                if(board[i] != 0){
                    cout << board[i] << "| \t";
                }
                else {
                    cout << i+1 << "| \t";
                }
            }
        }
    }
    cout << "------\t---------\t--------- \n";
    
    // thrid line of three boards
    for(int i=0; i< 27; i++){
        if(( i > 5 && i < 9) || (i > 14 && i < 18) || (i > 23 && i < 27)) {
            if(i%3 != 2) {
                if(board[i] != 0) {
                    cout << board[i] << "|";
                }
                else {
                    cout << i+1 << "|";
                }
            }
            else if(i == 26) {
                if(board[i] != 0){
                    cout << board[i] << "|" << endl;
                }
                else {
                    cout << i+1 << "|" << endl;
                }
            }
            else {
                if(board[i] != 0){
                    cout << board[i] << "| \t";
                }
                else {
                    cout << i+1 << "| \t";
                }
            }
        }
    }
    
    cout << "\n";
}

bool checkLegal(int cellNbre, char board[]) {
    // check if it is between 1 and 27	
    if(cellNbre < 1 || cellNbre > 27 ) {
        return FALSE;
    }
    // check if there is already O or X
    else if(board[cellNbre-1] == 'O' || board[cellNbre-1] == 'X') {
        return FALSE;
    }
    // check if the index is empty
    else if(board[cellNbre-1] != 0){
        return FALSE;
    }
    else{
        return TRUE;
    }
}

bool checkWinner(char board[]){
    // count if the board is full
    int counter=0;
    for(int i=0; i<27; i++) {
	// value of index divide by 3 which tells which row it is on    
        int c_val = i/3;

        if(board[i] != 0) {
            counter++;

	    // all the cases that uses 3 boards to win 
            if(i == 0) {
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
                if(board[i] == board[i+13] && board[i] == board[i+26]){
                    return TRUE;
                }
                if(board[i] == board[i+10] && board[i] == board[i+20]){
                    return TRUE;
                }
                if(board[i] == board[i+12] && board[i] == board[i+24]){
                    return TRUE;
                }
            }
            if(i == 1){
                if(board[i] == board[i+12] && board[i] == board[i+24]){
                    return TRUE;
                }
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
            }
            if(i == 2){
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
                if(board[i] == board[i+11] && board[i] == board[i+22]){
                    return TRUE;
                }
                if(board[i] == board[i+12] && board[i] == board[i+24]){
                    return TRUE;
                }
                if(board[i] == board[i+8] && board[i] == board[i+16]){
                    return TRUE;
                }
            }
            if(i == 3){
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
                if(board[i] == board[i+10] && board[i] == board[i+20]){
                    return TRUE;
                }
            }
            if(i == 4 || i == 7){
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
            }
            if(i == 5){
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
                if(board[i] == board[i+8] && board[i] == board[i+16]){
                    return TRUE;
                }
            }
            if(i == 6){
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
                if(board[i] == board[i+7] && board[i] == board[i+14]){
                    return TRUE;
                }
                if(board[i] == board[i+6] && board[i] == board[i+12]){
                    return TRUE;
                }
                if(board[i] == board[i+10] && board[i] == board[i+20]){
                    return TRUE;
                }
            }
            if(i == 8){
                if(board[i] == board[i+9] && board[i] == board[i+18]){
                    return TRUE;
                }
                if(board[i] == board[i+5] && board[i] == board[i+10]){
                    return TRUE;
                }
            }
            
	    // check for all the cases that you can win by on first row of boards
            if(c_val == 0 || c_val == 3 || c_val == 6){
                if(i%3 == 0) {
                    if(board[i] == board[i+1] && board[i] == board[i+2]) {
                        return TRUE;
                    }
                    if(board[i] == board[i+3] && board[i] == board[i+6]) {
                        return TRUE;
                    }
                    if(board[i] == board[i+4] && board[i] == board[i+8]) {
                        return TRUE;
                    }
                }
                
                if(i%3 == 1){
                    if(board[i] == board[i+3] && board[i] == board[i+6]) {
                        return TRUE;
                    }
                }
                
                if(i%3 == 2){
                    if(board[i] == board[i+3] && board[i] == board[i+6]) {
                        return TRUE;
                    }
                    if(board[i] == board[i+2] && board[i] == board[i+4]) {
                        return TRUE;
                    }
                }
            }
	    // check for all cases you can win on second row
            else if(c_val == 1 || c_val == 4 || c_val == 7) {
                if(i%3 == 0){
                    if(board[i] == board[i+1] && board[i] == board[i+2]) {
                        return TRUE;
                    }    
                }
            }
	    // check for all cases you can win on thrid row of the boards
            else if(c_val == 2 || c_val == 5 || c_val == 8) {
                if(board[i] == board[i+1] && board[i] == board[i+2]) {
                    return TRUE;
                }
            }
        }    
    }
    if(counter == 27) {
        cout << "The game is tied! There is no winner :( " << endl << "Game over!";
        exit(3);
    }
    return FALSE;
}

void computerMove(char board[]) {
    // check if computer can make a winning move
    for(int i=0; i< 27; i++) {
        if(board[i] == 0){
            board[i] = 'O';
            if(checkWinner(board)) {
                return;
            }
            else {
                board[i] = 0;
            }
        }
    }
    // check if computer can block a winning move
    for(int i=0; i<27; i++) {
        if(board[i] == 0){
            board[i] = 'X';
            if(checkWinner(board)) {
                board[i] = 'O';
                return;
            }
            else{
                board[i] = 0;
            }
        }
    }
    // if there is no move to make, just put O in order of the board index
    for(int i=0; i<27; i++){
        if(board[i] == 0){
            board[i] = 'O';
            return;
        }
    }
}
