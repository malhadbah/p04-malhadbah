#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
   .::Tic Tac Toe!::. .::Mohammed Alhadbah::.

  created a tic tac toe game,, but the special thing is that you can see the the final shape of the board... also
  it shows the final result of the two players..
  soon i will add another good feature, which is that i will change one rule that will make the game more interesting
  Ex: if a player already chooses a cell, the other player can remove it and put his symbol instead..
  So at the end .. my tic tac toe game will be more complex and challenging !
 */

//define size of board
#define SIZE 3

//The symbols that will be used in the game
#define X 'X'
#define O 'O'
#define EMPTY ' '

// need to make a class that will represent a board
class Board{

        public:

                //constructor
                Board(){
                        //create a board with empty cells
                        initializeBoard();
                }

                //check if the board is full 
                //the board is 2D array "3x3 game board"
                bool isFull(){
                        //for each row
                        for(int r=0; r<SIZE; r++){
                                //for each column
                                for(int c=0;c<SIZE;c++){
                                        if(board[r][c]==EMPTY){
                                                return false;
                                        }
                                }
                        }
                        //return true if the board is full.. else, return false
                        return true;
                }

                //check if the player won
                bool isWin(char player){
                        //check horizontally 
                        for(int r=0;r<SIZE;r++){  
                                int count=0;  //count the number of x or O 
                                for(int c=0; c<SIZE;c++){
                                        if(board[r][c] == player){
                                                count++;
                                        }
                                }
                                if(count == SIZE){
                                        return true;
                                }
                        }

                        //check vertically
                        //for each column
                        for(int c=0;c<SIZE;c++){
                                int count=0; //will count the number of x nad o (player)
                                for(int r=0;r<SIZE;r++){
                                        if(board[r][c]==player){
                                                count++;
                                        }
                                }
                                if(count==SIZE){
                                        return true;
                                }
                        }

                        //check diagonally
                        int count=0; //count the number of x or o
                        for(int r=0;r<SIZE;r++){
                                if(board[r][r]==player){
                                        count++;
                                }
                                if(count==SIZE){
                                        return true;
                                }
                        }

                        //check diagonally /
                        //added because when I checked the the winning conditions it was missing
                        count=0;
                        for(int r=0;r<SIZE;r++){
                                if(board[r][SIZE-r-1]==player){
                                        count++;
                                }
                                if(count == SIZE){
                                        return true;
                                }
                        }
                        return false;
                }

                /*  print the board

                      1 2 3
                     +-+-+-+
                    1|1|2|3|
                     +-+-+-+
                    2|4|5|6|
                     +-+-+-+
                    3|7|8|9|
                     +-+-+-+

                 */
                void printBoard(){
                        //print colunm name
                        cout<<"   ";
                        for(int c=0;c<SIZE;c++)
                        {
                                cout<<" "<<c+1;
                        }
                        //print +-+-+-+
                        cout<<endl<<"   ";
                        for(int c=0;c<SIZE;c++)
                        {
                                cout<<"+-";
                        }
                        cout<<"+"<<endl;

                        //print rows
                        for(int r=0; r<SIZE;r++)
                        {
                                cout<<" "<<r+1<<" ";
                                //print columns
                                for(int c=0;c<SIZE;c++)
                                {
                                        cout<<"|"<<board[r][c];
                                }
                                cout<<"|"<<endl;

                                //print +-+-+-+
                                cout<<"   ";
                                for(int c=0;c<SIZE;c++)
                                {
                                        cout<<"+-";
                                }
                                cout<<"+"<<endl;
                        }
                }

                //check if cell is empty
                bool isEmptyCell(int r, int c){
                    return board[r][c] == EMPTY;
                    }
                    //put x or o to cell
                void setCell(int r, int c, char player){
                        board[r][c]=player;
                        }

                        private:

                        char board[SIZE][SIZE];

                        //initialize board with empty cell
                        void initializeBoard(){
                                for(int r=0;r<SIZE;r++)
                                {
                                        for(int c=0;c<SIZE;c++){
                                                board[r][c]=EMPTY;
                                        }
                                }
                        }
                };

                //win score
#define WIN_SCORE 10

                //data file name
#define GAME_DATA_FILE "data.txt"

                //read a position (row,col) to put a player symbol xo
                void readPosition(Board &boardObject, int &row, int &col, string prompt);

                void displayGameHistory();

                //display menu and get user selection
                string menu();

                //play a game and return winner or empty if tie
                char playGame();

                //save game into file
                void saveGame(string Xname, string Oname, int Xscore, int Oscore);

                int main(){

                        //name of players
                        string Xname, Oname;

                        int Xscore=0;  //X user score for all games
                        int Oscore=0;  //O user score for all games
                        char winner;   //one player winner

                        //players name
                        cout<<"please enter the name of X player: ";
                        getline(cin, Xname);

                        cout<<"please enter the name of O player: ";
                        getline(cin, Oname);

                        string selection= menu(); //display a menu and read the user selections

                        while(selection != "3")
                        {
                                if(selection== "1"){

                                        displayGameHistory();

                                }else if(selection == "2")
                                {

                                        //play game
                                        winner=playGame();

                                        if(winner==X)
                                        {
                                                Xscore += WIN_SCORE;
                                        }else if(winner==O)
                                        {
                                                Oscore += WIN_SCORE;
                                        }
                                }else{//invalid selections
                                        cout<<"invalid selection"<<endl;
                                }
                                cout<<endl;

                                //must repeat the menu again even if the user didn't selected the right choice
                                selection=menu();
                        }

                        saveGame(Xname, Oname, Xscore, Oscore);

                        cout<<endl<<"thank you and Good bye!"<<endl;

                        return 0;
                }

                //read a position (row, col) to put player symbol
                void readPosition(Board &boardObject, int &row, int &col, string prompt){

                        string input="";
                        bool valid=false; //validate

                        //loop until it's valid
                        while(!valid){

                                //read input
                                cout<<prompt;
                                getline(cin, input);

                                if(input.length()==2)
                                {
                                        //extract row, column
                                        row = input[0]-'1';
                                        col = input[1]-'1';

                                        if(row<0 || row>=SIZE || col<0 || col>=SIZE)
                                        {
                                                cout<<"invalid input"<<endl;
                                        } else if(!boardObject.isEmptyCell(row, col)){
                                                cout<<"The position is not empty"<<endl;
                                        } else{
                                                valid=true;
                                        }
                                }else{
                                        cout<<"Ivalid input"<<endl;
                                }
                        }
                }

                //display game history
                void displayGameHistory(){

                        //input data file
                        ifstream inFile;

                        string line; //line from file

                        inFile.open(GAME_DATA_FILE);

                        if(!inFile){
                                cout<<"Unable to open file"<<GAME_DATA_FILE;
                        }else{
                                //read line by line until end of file
                                while(getline(inFile,line))
                                {
                                        cout<<line<<endl;
                                }
                                inFile.close();
                        }
                }

                string menu(){

                string selection;

                cout<<" 1. View game history"<<endl;
                cout<<" 2. Play game"<<endl;
                cout<<" 3. Quit application"<<endl;

                cout<<"Enter your selection? ";
                getline(cin, selection);

                return selection;
               }

                char playGame(){

                        int row, col; //row column for player

                        char turn = X; //current turn

                        bool gameEnd = false;

                        Board boardObject; //board object

                        boardObject.printBoard(); 

                        //play one game
                        while(!gameEnd){

                                cout<<"----"<<turn<<"'s turn ----"<<endl;

                                //read row, column for player at turn (valid position)
                                readPosition(boardObject, row, col, "Please enter a position: ");

                                //put symbol at this position
                                boardObject.setCell(row, col, turn);

                                cout<<endl;

                                //check win
                                if(boardObject.isWin(turn)){
                                        cout<<turn<<" won"<<endl<<endl;
                                        gameEnd = true;
                                }else if(boardObject.isFull()){
                                        cout<<"Game ties"<<endl<<endl;
                                        turn = EMPTY;
                                        gameEnd = true;
                                }

                                if(!gameEnd){//swap turn
                                        if(turn == X){
                                                turn = O;
                                        }else{
                                                turn = X;
                                        }
                                }
                                boardObject.printBoard();
                        }
                        return turn;
                }

                void saveGame(string Xname, string Oname, int Xscore, int Oscore){

                        ofstream outfile;

                        outfile.open(GAME_DATA_FILE, ios::out | ios::app);
                        outfile<<Xname<<": "<<Xscore<<", "<<Oname<<"; "<<Oscore<<"\n";

                        outfile.close();
                }
