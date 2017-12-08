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
  
  
  Data Structure:
  
  
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
  
  
  File IO:
  
  
  Class:
  
  
