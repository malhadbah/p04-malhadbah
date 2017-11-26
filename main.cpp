#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
 .::Tic Tac Toe!::. .::Mohammed Alhadbah::.
*/

//define size of board
#define SIZE 3

//The symbols that will be used in the game
#define X 'X'
#define O 'O'
#define EMPTY ' '

// need to make a class that will represent a board
class board{

public:

    //constructor
    board(){
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
        for(int r=0;r<SIZE;r++){  //for each row
        int count=0;  //count the number of x or O 
            for(int c=0; c<SIZE;c++){
                if(board[r][c] == player){
                    count++;
                }
            }
            if (count == SIZE){
                return true;
            }
      }

      //check vertically
      //for each column
      for(int c=0;c<SIZE;c++){
        int count=0; //will count the number of x nad o (player)
            for(r=0;r<SIZE;r++){
                if(board[r][c]==player){
                    count++;
                }
            }
            if (count==SIZE){
            return true;
            }
      }
      
      //check diagonally
      int count=0; //count the number of x or o
      for(int r=o;r<SIZE;r++){
        if(board[r][r]==player){
            count++;
        }
        if(count==SIZE){
        return true;
        }
      }

      
        
      }
      return false;
  }
  
  /*  print the board

     1 2 3
    +-+-+-+
 1  |1|2|3|
    +-+-+-+
 2  |4|5|6|
    +-+-+-+
 3  |7|8|9|
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

//read a position (row,col) to put a player symbol xo
void readPosition(Board &bordObject, int &row, int &col, string prompt);

//display game history
void displyGameHistory();

//display menu and get user selection
string menu();

//play a game and return winner or empty if tie
char playGame();

//save game into file

//main function begins
int main(){

//name of players
string Xname, Oname;

int Xscore=0;  //X user score for all games
int Oscore=0;  //O user score for all games
char winner;   //one player winner

//players name
cout<<"please enter the name of X player: "<<endl;
getline(cin, Xname);

cout<<"please enter the name of O player: "<<endl;
getline(cin, Oname);

//creating a menu 
string selection= menu(); //display a menu and read the user selections

// i like while loop :p
while(selection != "3"){
if(selection== "1"){
//display game history

displayGameHistory();

}else if(selection == "2")
{
//play game

winner=playGame();

if(winner==X)
{
Xscore +=WIN_SCORE;
}else if(winner==0)
{
Oscore+= WIN_SCORE;
}
}else{//invalid selections
cout<<"invalid selection"<<endl;
}
cout<<endl;
//must repeat the menu again even if the user didn't selected the right choice
selection=menu();
}//end of while loop

return  0;
}

//read a position (row, col) to put player symbol
 void readPosition(Board &boardObject, int &row, int &col,string prompt){


//display game history
//input data file
//open file
//display menu and most not foget to add the 3selections and to return the right selection
 void displayGameHistory(){


char playGame(){
