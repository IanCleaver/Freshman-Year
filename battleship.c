/*
 * Author:  Ian Cleaver, icleaver2018@my.fit.edu
 * Course:  CSE 1002, Section 02, Spring 2019
 * Project: Assignment #1, Battleship
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMap(int rows, int columns,char board[][columns],char userboard[][columns]);
void readMap(int shots,int *rowsptr, int *columnsptr,FILE* fptr);
int playGame(int rows,int columns,char board[][columns],char userboard[][columns],int shots);



int main(int argc, char *argv[]){
	int columns=0, rows=0;
	int *rowsptr;
		rowsptr = &rows;
	int *columnsptr;
		columnsptr = &columns;
//File Pointer
	FILE *fptr;
    char filename[15];
    int shots = *argv[1] - '0';
	shots = atoi(argv[1]);
	//printf("%d\n",shots);
	char file[150] = "./";
	strcat(file,argv[2]);
//Open file, if unable print error message
			fptr = fopen(file, "r");
			if (fptr == NULL)
			{
				printf("Cannot open file \n");
				exit(0);
			}
	
		readMap(shots,rowsptr,columnsptr,fptr);
	
	
//close file to prevent memory overflow
fclose(fptr);
return 0;
}

void readMap(int shots,int *rowsptr, int *columnsptr,FILE* fptr){
//variable for counting shots

//reading the rows and columns from the file
		fscanf(fptr,"%d %d",rowsptr,columnsptr);
		//	printf("The rows are %d\n",*rowsptr);
		//	printf("The columns are %d\n",*columnsptr);
	
//Initial board to compare with user board
		int temp = 0;
		char x;
		char board[*rowsptr][*columnsptr];
//Reading file into array and checking it in a propper form, suitable for mac and windows
		if(fptr!=NULL){
			for(int i = 0;i<*rowsptr;i++){
				for(int j = 0;j<*columnsptr;){
					temp = fgetc(fptr);
					if(temp==126 || temp == 66){
						x = (char)temp;
						board[i][j] = x;
						j++;
					}else if(temp==13||temp==10){
					}else{
						printf("ERROR: File is not suitable for this game.\n");
						exit(0);
					}
				}
			}
		}else {
//In case board is not suitable
			printf("YOU HAVE MISTAKEN ERROR 404 FILE NOT FOUND\n"); 
			exit(0);
		}
//Userboard filled with '~', only user sees this board
		char userboard[*rowsptr][*columnsptr];
				for(int i = 0;i<*rowsptr;i++){
					for(int j = 0;j<*columnsptr;j++){
						userboard[i][j]='~';
					}
				}
		
				
		int win_check = 0;
//Calls function and places return value into variable	
			win_check = playGame(*rowsptr,*columnsptr,board,userboard,shots);
				printMap(*rowsptr,*columnsptr,board,userboard);
				printf("\n");
//check if player won or loses
				if(win_check == 0){
					printf("Captain, we ran out of ammo. You lose!");
				}else if(win_check == 1){
					printf("Captain, we have sunk all the battleships. You win!");
						exit(0);
				}	
				
}

void printMap(int rows,int columns,char board[][columns],char userboard [][columns]){
	
//prints map in a double for loop
	for(int i = 0;i<rows;i++){
		printf("\n");
		for(int j = 0;j<columns;j++){
			printf("%c",userboard[i][j]);
		}
	}
	
}

int playGame(int rows,int columns,char board[][columns],char userboard[][columns],int shots){
	int x=0;
	int y=0;
	int hits = 0;
	int totalships=0;
//Counts how many ships there are in the board to compare and check for win
		for(int i = 0;i<rows;i++){
			for(int j = 0;j<columns;j++){
				if(board[i][j]=='B'){
					totalships++;
				}
			}
		}
//Where the game is actually played
		while(shots>0){
			printf("\nMAP");
			
			printMap(rows,columns,board,userboard);
			
				printf("\n%d. shots remaining.\n",shots);
				printf("Capatain, please enter the cordinates: ");
				scanf("%d %d",&x,&y);
				
				while(getchar()!='\n');
				
					if(((x>=rows)||(x<0))&&((y>columns)||(y<0))){
						printf("ERROR: Out of bounds.");
						shots++;
					}else if((x>=rows)||(x<0)){
						printf("ERROR: Out of bounds.");
						shots++;
					}else if((y>=columns)||(y<0)){
						printf("ERROR: Out of bounds.");
						shots++;
					}else{
//If it hits it adds to hits counter to compare with amount of ships
						if(board[x][y]=='B'){
							printf("HIT!\n");
							userboard[x][y]='H';
							board[x][y]='H';
							hits++;
						}else if(board[x][y]=='~'){
							printf("MISS!\n");
							userboard[x][y]='M';
							board[x][y]='M';
						}else if((board[x][y]=='M')||(board[x][y]=='H')){
							printf("ERROR: Already shot in that possition");
							shots++;
						}else{
//Debug statement 
							printf("Ian Did bad");
						}

					}
shots--;
//return value if win or lose
					if(hits==totalships){
						return 1;
					}else if(shots == 0){
						return 0;
					}		
		}
}