#ifndef BOARD_H
#define BOARD_H

#include <iostream> 
#include <string>   
#include <fstream>   
using namespace std;

//define of size of board
#define SIZE 3

//player symbols or empty cell
#define X 'X'
#define O 'O'
#define EMPTY ' '


class Board{

        public:

                //constructor
                Board();

                //copy constructor
                Board(const Board &other);

                //assignment overloading
                //check self-assignment
                Board& operator= (const Board &other);

                //output stream overloading operator
                //print the board the stream
                //it is called by cout << <Board object>
                friend ostream& operator<<(ostream& out, const Board &b);

                //check if board is full
                bool isFull();

                //check if player win
                
                bool isWin(char player);

                //check if cell is empty
                bool isEmptyCell(int r, int c);

                //subscript operator
                //return the reference to the specific postion
                //the calling code can replace that value or read that value
                char& operator() (const int row, const int col);

        private:

                //two-dimension array that represents a board
                char board[SIZE][SIZE];

                //initialize board with empty cell
                //set each element by EMTPY (' ' character)
                void initializeBoard();
};
#endif
