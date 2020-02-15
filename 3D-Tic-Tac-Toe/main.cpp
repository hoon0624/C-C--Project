#include <iostream>
#include <limits>

using namespace std;
bool TRUE = 1;
bool FALSE = 0;
bool startGame = FALSE; 

void greetAndInstruct();
void displayBoard(char board[]);
bool checkLegal(int cellNbre, char board[]);
bool checkWinner(char board[]);
void computerMove(char board[]);



int main()
{
    // game board
    char board[27] = {};
    int cellNbre=0;
    greetAndInstruct();
    
    //start game if answer is y
    if (startGame == TRUE) {
        cout << "Game starting!" << endl;
        
        while(!checkWinner(board)) {
            displayBoard(board);
            
            cout << "Choose cell number: ";
            // check if it is valid cell number and if it is put X  
            while(!checkLegal(cellNbre, board)){
                
                cin >> cellNbre;
		if(cin.fail()){
		    cout << "Please choose a valid cell number: ";
		    cin.clear();
		    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');               
		}
		else if(checkLegal(cellNbre, board)) {
                    board[cellNbre-1] = 'X';
                    break;
                } 
                else {
                    cout << "Please choose a valid cell number: ";
                }
            }
            // check if player has won
            if(checkWinner(board)) {
                cout << "Player has won! Congratulation!";
                break;
            }
            // computer makes a move
            computerMove(board);
	    // check if computer has won
            if(checkWinner(board)) {
                cout << "Computer has won! Try again!";
                break;
            }
        }
    }

    return 0;
}






