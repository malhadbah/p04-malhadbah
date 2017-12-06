#include "Board.h"

//constructor
Board::Board(){
        //initialize board with empty cell
        initializeBoard();
}

//copy constructor
//copy the board from other object to this object
Board::Board(const Board &other){
              
        for (int r = 0; r < SIZE; r++){
                
                for (int c = 0; c < SIZE; c++){
                        board[r][c] = other.board[r][c];
                }
        }
}

//assignment overloading
//check self-assignment
//copy board from other object to this board
Board& Board::operator= (const Board &other)
{
        // self-assignment
        if (this == &other)
                return *this;

              
        for (int r = 0; r < SIZE; r++){
                
                for (int c = 0; c < SIZE; c++){
                        board[r][c] = other.board[r][c];
                }
        }

        // return the existing object
        return *this;
}

bool Board::isFull(){
              
        for (int r = 0; r < SIZE; r++){
                
                for (int c = 0; c < SIZE; c++){
                        if (board[r][c] == EMPTY){
                                return false;
                        }
                }
        }
        return true;
}

bool Board::isWin(char player){
        //check horizontally
        for (int r = 0; r < SIZE; r++){
                int count = 0; //count the number of X or O (player)
    
                for (int c = 0; c < SIZE; c++){
                        if (board[r][c] == player){
                                count++;
                        }
                }
                if (count == SIZE){
                        return true;
                }
        }

        //check vertically
        for (int c = 0; c < SIZE; c++){
                int count = 0; //count the number of X or O (player)
      
                for (int r = 0; r < SIZE; r++){
                        if (board[r][c] == player){
                                count++;
                        }
                }
                if (count == SIZE){
                        return true;
                }
        }

        //check diagonally 
        int count = 0; //count the number of X or O (player)
        for (int r = 0; r < SIZE; r++){         
                if (board[r][r] == player){
                        count++;
                }
                if (count == SIZE){
                        return true;
                }
        }

        //check diagonally /
        count = 0; //count the number of X or O (player)
        for (int r = 0; r < SIZE; r++){
                if (board[r][SIZE - r - 1] == player){
                        count++;
                }
                if (count == SIZE){
                        return true;
                }
        }

        return false;
}

bool Board::isEmptyCell(int r, int c){
        return board[r][c] == EMPTY;
}

//subscript operator
//return the reference to the specific postion
//the calling code can replace that value or read that value
char& Board::operator() (const int row, const int col){
        return board[row][col];
}

/*   
      1 2 3
     +-+-+-+
   1 |X|X| |
     +-+-+-+
   2 | |O|O|
     +-+-+-+
   3 |X|O| |
     +-+-+-+
 */

ostream& operator<<(ostream& out, const Board &b){
        //print column name
        out << "   ";
        for (int c = 0; c < SIZE; c++)
        {
                out << " " << c + 1;
        }
        //print +-+-+-+
        out << endl << "   ";
        for (int c = 0; c < SIZE; c++)
        {
                out << "+-";
        }
        out << "+" << endl;

        //print rows
        for (int r = 0; r < SIZE; r++)
        {
                out << " " << r + 1 << " ";
                //print columns
                for (int c = 0; c < SIZE; c++)
                {
                        out << "|" << b.board[r][c];
                }
                out << "|" << endl;

                //print +-+-+-+
                out << "   ";
                for (int c = 0; c < SIZE; c++)
                {
                        out << "+-";
                }
                out << "+" << endl;
        }

        return out;
}

void Board::initializeBoard(){
        
        for (int r = 0; r < SIZE; r++)
        {
               
                for (int c = 0; c < SIZE; c++){
                        board[r][c] = EMPTY;
                }
        }
}


