/*
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
   
*/
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void display();
int lvl,sz,BOARD[10][10];
char CPY[10][10];
int loc_x=0,loc_y=0,s_count=0,scr=0;
int main(){
	int r,c;
	printf("Select Level: 1-Easy 2-Medium 3-Hard:");
	scanf("%d",&lvl);
	
	//Set board size as per difficulty level.
	switch(lvl){
		case 1:BOARD[4][4],CPY[4][4];sz=4;break;
		case 2:BOARD[7][7],CPY[7][7];sz=7;break;
		case 3:BOARD[10][10],CPY[10][10];sz=10;break;
		default:printf("ERROR!!!");return 0;
	}
	
	//INITIALIZATION OF BOARD.
	for(int i=0;i<sz;i++)
	    for(int j=0;j<sz;j++)
	    	CPY[i][j]='*';
	    	
	srand(time(0));
	for(int i=0;i<sz;i++){
		r=rand()%4,c=rand()%4;
		BOARD[r][c]=1;
		for(int j=0;j<sz;j++){
			if(BOARD[i][j]!=1)
			    BOARD[i][j]=0;
		}
	}
	
	//DISPLAY THE BOARD.
	display();
	
	//LETS PLAY.
	while(BOARD[loc_x][loc_y]!=1||s_count!=(sz-1)*sz){
		printf("Enter location: ");
		scanf("%d %d",&loc_x,&loc_y);
		
		//Check if there is no mine at that location.
		if(BOARD[loc_x][loc_y]!=1){
			s_count++;
			CPY[loc_x][loc_y]='0';
			system("cls");
			display();
			printf("\n");
		}
		
		//When the user enters the same location again:
		else if(BOARD[loc_x][loc_y]==0){
			printf("\nYou've already entered this location. Try again! ");
		}
		
		//If the user steps on a mine...then print score and exit.
		else{
			CPY[loc_x][loc_y]='X';
			system("cls");
			display();
			printf("\nOOps! You Stepped on a land mine. *_*");
			printf("\nScore: %d",(s_count*100)/sz/sz);
			break;
		}
	}

    //If the user checks out all the location with no mines, then print score. 
	if(s_count==(sz-1)*sz){
		system("cls");
		display();
		printf("\nYou Won!\nScore: 100");
		return 1;
	}
	
	
}

void display(){
	//This function display the game board.
	printf("      ");
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++)
		    printf("%c ",CPY[i][j]);
		printf("\n      ");
	}
	printf("\n");
}
