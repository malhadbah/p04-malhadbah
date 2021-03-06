  # p04-malhadbah

Tic Tac Toe Game 

  Game Rules:
 
    1- A player must choose a cell from 1 to 9
          1|2|3
          4|5|6
          7|8|9
          
    2- Each player must choose either 'X' or 'O'
    
    3- The game will end if the cells are full
    
    4- 'x' player always goes first
 
 The Goal:
 
 The goal of Tic Tac Toe is to be the first player to get three in a row on a 3x3 grid.
 
 What's Interesting ??
 
  1- Be careful. I have added a new rule, which is that any player ( X or O ) can remove the symbol of the other player.

  2- The last shape of the board will appear after the game.
 
  3- A file will show the players name and the scores.
 
 Hint: two expert players might draw :)
 
 -------------------
 
  User Input/Output:
 
 
 [main.cpp lines 40-41](/main.cpp)
 asks the 'X' player for his name
 
 [main.cpp lines 44-45](/main.cpp)
 asks for 'O' player name
 
 [main.cpp lines 146-158](/main.cpp)
 shows the menu to the players and asks for selecion
 
 [Board.cpp lines 133-163](/Board.cpp)
 will print the board rows columns (design)
 
 
  Control flow constructs:
  
  

[main.cpp lines 53](/main.cpp)
   it means if the user selected the first choice in the menu.
 
   [main.cpp lines 58](/main.cpp)
   if the user selected the second choice in the menu.
 
   [main.cpp lines 63](/main.cpp)
   if the winner is 'X' player
 
 [main.cpp lines 66](/main.cpp)
 if the winner is player 'O'
 
 [main.cpp lines 71](/main.cpp)
 it means if the user selected any number or letter other than 1 2 or 3. the input is invalid.
 the menu will show again.
 

[main.cpp lines 105-118](/main.cpp)
 else if to check the position of the user input if it's valid or not
 
 [main.cpp lines 134](/main.cpp)
 to check if it's not the file then it won't open.
 
 [Board.cpp lines 47](/Board.cpp)
 to check if the board is full.
 
 [Board.cpp lines 61-101](/Board.cpp)
 conditions to check how the player will win by the game rules (vertically, horizontally, or diagonally).
 
 
  iteration:
  
  
  
  [main.cpp lines 98](/main.cpp)
  while loop and it will loop until the user enters a valid position
  
  [main.cpp lines 138](/main.cpp)
  while lopp and it will read line by line until the end of file
  
  [main.cpp lines 176](/main.cpp)
  will play a game while the game is not finished "needs to win or tie"
  
  [Board.cpp lines 169-178](/Board.cpp)
  for loop to initialze a board with default value (empty cells)
  
  [Board.cpp lines 132-159](/Board.cpp)
  for loop to print the board rows and cols
  
  

Data Structure:
  
  
  
   [Board.cpp lines 44-47](/Board.cpp) 
  board is 2-D array (3x3 game board). To check if the cells are full
  
   [Board.cpp lines 57-101](/Board.cpp) 
  arrays to check if one of the player won.
  
   [Board.cpp lines 171-174](/Board.cpp) 
   array to intialize a board with empty cells "default
   
   
  Functions:
  
  
  
  [main.cpp lines 15](/main.cpp) 
  to read the position or where the player wants to put the symbol Ex: 11 or 22  (row,column)
  
  [main.cpp lines 18](/main.cpp)
  read from file GAME_DATA_FILE line by line, and show in the standard output
  
  [main.cpp lines 21](/main.cpp)
  display menu and gets the user selection from the menu, it will return the selection.
  
  [main.cpp lines 24](/main.cpp)
  The function will check if it's full or win, return who wins ('x' or 'o') or empty is returned if tie.
  The function will call other functions to validate row & column.
  
  [main.cpp lines 27](/main.cpp)
  This function will save the game into file with names and scores.
  
  [Board.cpp lines 3-19](/Board.cpp)
 Constructors are functions without a return type, can't all it 
 it implement itslef when you do create a constructor.
 to initialize the board with empty cells,,copy the board from other object to this object
 
  [Board.cpp lines 24-39](/Board.cpp)
  The assignment operator (operator=) is used to copy values from one object to another already existing object.
  the copy constructor initializes new objects, whereas the assignment operator replaces the contents of existing objects.
  
  [Board.cpp lines 42](/Board.cpp)
  check if the baord is full, to know if the game should end or not. all cells need to be filled with symbols X or O
  return true if board is full; otherwise, return false
  
  [Board.cpp lines 55](/Board.cpp)
  to check all conditions of winning.. either horizontally, vertically or diagonally \/
  
  ,if 3 elements in the same row or column are player: win
  ,if 3 elements in vertically are player: win
  otherwise, return false
  
  [Board.cpp lines 109](/Board.cpp)
  check if the cells are empty
  
  
  File IO:
  
  
  
   [main.cpp lines 214](/main.cpp) 
   The name of x player and o player + the scores of both will be saved in txt file, after each game the new scores will be added.
  
  
   [main.cpp lines 127-142](/main.cpp) 
   will display game history from the file.
   
  
  Class:
  
  
  [Board.h lines 18](/Board.h)
 created a Board class and added all the functions that are related to board in this class 
 Board.h is the interface design
 anything that doesn't need to be edited by the user's are in private.
