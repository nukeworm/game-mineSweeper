# game-mineSweeper

Author:          nukeworm
   Github:          @nukeworm
   Project name:    game-mineSweeper
   Version:         1.01
   Buit on:         4/11/2019
   
   ----Description----
   This game was inspired by the classic 'Cube' by Jerimac Ratliff.
   It's a little different since you get no hints or clues where the mines are located.
   It depends solely on your luck to survive in this game and is pretty difficult to win.
   
   ----Working----
   User has to enter a location where he wants to step-on.If theres a mine on that location,
   he loses, else he enters another location and this process is repeated until every safe location
   is dicovered or steps on a mine.The game board is displayed on every step.
   The score is displayed at the end of the match, although this can be changed to display the score at every step.
   
   ----Calculation of Score----
   Score is the percented of safe locations he steps on.
   Suppose there are 12 safe locations and he discovers only 3 of them,
   then the score will be 25 { (3*100)/12 }.
