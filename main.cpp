#include <iostream> 
#include <string>   
#include <fstream>   
#include "Board.h"

using namespace std;

//win score
#define WIN_SCORE 10

//data file name
#define GAME_DATA_FILE "data.txt"

//read a position (row, col) to put player symbol
void readPosition(Board &boardObject, int &row, int &col, string prompt);

//display game history
void displayGameHistory();

//display menu and get user selection
string menu();

//play a game and return winner or empty if tie
char playGame();

//save game to file
void saveGame(string Xname, string Oname, int Xscore, int Oscore);

//main function
int main(){

        //name of players
        string Xname, Oname;

        int Xscore = 0;    //X user score for all games
        int Oscore = 0;    //O user score for all games
        char winner; //winner for one game

        //prompt for first player's name
        cout << "Please enter the name of X player: ";
        getline(cin, Xname);

        //prompt for second player's name
        cout << "Please enter the name of O player: ";
        getline(cin, Oname);

        //display menu and read user selection
        string selection = menu();

        //allows to play until they are ready to quit
        while (selection != "3"){

                if (selection == "1")
                {//display game history

                        displayGameHistory();

                }else if (selection == "2")
                {//play game

                        winner = playGame();

                        if (winner == X)
                        {
                                Xscore += WIN_SCORE;
                        }else if (winner == O)
                        {
                                Oscore += WIN_SCORE;
                        }

                }else{//invalid selection
                        cout << "Invalid selection" << endl;
                }

                cout << endl;

                selection = menu(); //display menu and read user selection

        }//end while

        //save game
        saveGame(Xname, Oname, Xscore, Oscore);

        cout << endl << "Thank you and Good bye!" << endl;

        return 0;
}




void readPosition(Board &boardObject, int &row, int &col, string prompt){

        string input = ""; //input e.g. C1 or c1
        bool valid = false; //validate

        //loop until it is valid
        while(!valid){

                //read input
                cout << prompt;
                getline(cin, input);

                //it must be 2 digits
                if (input.length() == 2)
                {
                        //extract row, column
                        row = input[0] - '1';
                        col = input[1] - '1';

                        //validate indices
                        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
                        {
                                cout << "Invalid input" << endl;
                        }else{
                                valid = true;
                        }
                }else{
                        cout << "Invalid input" << endl;
                }
        }
}


void displayGameHistory(){

        //input data file
        ifstream inFile;

        string line;//line from file

        //open file
        inFile.open(GAME_DATA_FILE);
        if (!inFile) {
                cout << "Unable to open file " << GAME_DATA_FILE;
        }else{
                //read line by line until end of file
                while (getline(inFile, line))
                {
                        cout << line << endl;
                }
                inFile.close();
        }
}

//display menu and get user selection
//read a whole line and return
//this function does not check valid option
string menu(){

        string selection; //user's selection

        cout << "1. View game history" << endl;
        cout << "2. Play game" << endl;
        cout << "3. Quit application" << endl;

        cout << "Enter your selection? ";
        getline(cin, selection);

        return selection;
}

char playGame(){

        int row, col; 

        char turn = X;//current turn

        bool gameEnd = false; //end game

        Board boardObject;//Board object

        cout << boardObject;      

        //play one game
        while(!gameEnd){

                cout << "----" << turn << "'s turn ----" << endl;

                //read row, column for player at turn (valid position)
                readPosition(boardObject, row, col, "Please enter a position: ");   

                //put symbol at this position
                boardObject(row, col) = turn;

                cout << endl;

                //check win
                if (boardObject.isWin(turn)){
                        cout << turn << " won" << endl << endl;
                        gameEnd = true;
                }else if (boardObject.isFull()){
                        cout << "Game ties" << endl << endl;
                        turn =EMPTY;
                        gameEnd = true;
                }

                if(!gameEnd){//swap turn
                        if (turn == X){
                                turn = O;
                        }else{
                                turn = X;
                        } 
                }

                cout << boardObject; //print board
        }

        return turn;
}

void saveGame(string Xname, string Oname, int Xscore, int Oscore){

        ofstream outfile;//output stream

        outfile.open (GAME_DATA_FILE, ios::out | ios::app);
        outfile << Xname << ": " << Xscore <<  ", "
                << Oname << ": " << Oscore <<  "\n";
        //close file
        outfile.close();
}
