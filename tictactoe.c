/*        

*  Author: Ian Cleaver, icleaver2018@my.fit.edu              

*  Course: CSE 1001, Section 02, Fall 2018           

*  Project: tictactoe              

*/        
#include <stdio.h>

void draw_board(const char board[3][3]);
int check_win(char board[3][3]);
void do_board_index();
int do_check(const int n, const char board[3][3]);
void play(int n, int counter, char board[3][3]);
int do_draw(const char board[3][3]);

int main(void){
//Variable to check for win
int wincondition;
//Variable to check for draw
int drawcondition;
//counter switches from player 1 to player 2 and vice versa
int counter = 1;
//n is users input
int n;
//variable that helps check if input is valid
int checktable;
//board array
char board[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
//draw index for board
		do_board_index();
//While loop that indicates the beggining of the game
	while(1){
		printf("Player 1 choose a cell to play: ");
		scanf("%d",&n);
//Check If correct Input and cofirm input
			checktable = do_check(n,board);
		//Loop runs only if you cant play "n"
		while(checktable == -1){
			//false
			printf("Wrong move! The cell is already taken or invalid input!\n");
			printf("Player 1 Choose a cell to play: ");
			scanf("%d",&n);
				checktable = do_check(n,board);
		}
		printf("The cell chosen by player 1: %d\n",n);
//Play the input
		play(n,counter,board);
		counter++;
//print table
		draw_board(board);
//Check for Win if win break
			wincondition = check_win(board);
		if(wincondition==1){
			printf("Congratulations! Player 1 won the game!");
			break;
		}
			drawcondition = do_draw(board);
		if(drawcondition == 1){
			printf("The game is a DRAW!");
			break;
		}
//Player 2 plays
		printf("Player 2 choose a cell to play: ");
		scanf("%d",&n);
		//Check If correct Input and cofirm input
			checktable = do_check(n,board);
		//Loop runs only if you cant play "n"
		while(checktable == -1){
			//false
			printf("Wrong move! The cell is already taken or invalid input!\n");
			printf("Player 2 Choose a cell to play: ");
			scanf("%d",&n);
				checktable = do_check(n,board);
		}
		printf("The cell chosen by player 2: %d\n",n);
//Play the input
		play(n,counter,board);
		counter++;
//print table
		draw_board(board);
//Check for Win if win break
			wincondition = check_win(board);
		if(wincondition==1){
			printf("Congratulations! Player 2 won the game!");
			break;
		}
			drawcondition = do_draw(board);
		if(drawcondition == 1){
			printf("The game is a DRAW!");
			break;
		}
	}	
return 0;
}

void do_board_index(){
	int board_index[3][3]={1,2,3,4,5,6,7,8,9};
	
	for(int i = 0; i<3;i++){
		printf("|");
		for(int j = 0;j<3;j++){
			printf(" %d |",board_index[i][j]);
		}
		printf("\n");
	}
}

int do_check(const int n, const char board[3][3]){
	if((n<1)||(n>9)){
		return -1;
	}else if((n==1)&&(board[0][0]=='-')){
		return 1;
	}else if((n==2)&&(board[0][1]=='-')){
		return 1;
	}else if((n==3)&&(board[0][2]=='-')){
		return 1;
	}else if((n==4)&&(board[1][0]=='-')){
		return 1;
	}else if((n==5)&&(board[1][1]=='-')){
		return 1;
	}else if((n==6)&&(board[1][2]=='-')){
		return 1;
	}else if((n==7)&&(board[2][0]=='-')){
		return 1;
	}else if((n==8)&&(board[2][1]=='-')){
		return 1;
	}else if((n==9)&&(board[2][2]=='-')){
		return 1;
	}else{
		return -1;
	}	
}

void play(int n,int counter,char board[3][3]){
	if((counter % 2) != 0){
		if(n==1){
			board[0][0] = 'x';
		}else if(n==2){
			board[0][1] = 'x';
		}else if(n==3){
			board[0][2] = 'x';
		}else if(n==4){
			board[1][0] = 'x';
		}else if(n==5){
			board[1][1] = 'x';
		}else if(n==6){
			board[1][2] = 'x';
		}else if(n==7){
			board[2][0] = 'x';
		}else if(n==8){
			board[2][1] = 'x';
		}else if(n==9){
			board[2][2] = 'x';
		}else{
			printf("IAN DID BAD");
		}
	}else if((counter % 2) == 0){
		if(n==1){
			board[0][0] = 'o';
		}else if(n==2){
			board[0][1] = 'o';
		}else if(n==3){
			board[0][2] = 'o';
		}else if(n==4){
			board[1][0] = 'o';
		}else if(n==5){
			board[1][1] = 'o';
		}else if(n==6){
			board[1][2] = 'o';
		}else if(n==7){
			board[2][0] = 'o';
		}else if(n==8){
			board[2][1] = 'o';
		}else if(n==9){
			board[2][2] = 'o';
		}else{
			printf("IAN DID BAD");
		}
	}
}

void draw_board(const char board[3][3]){
	for(int i = 0; i<3;i++){
		printf("|");
		for(int j = 0;j<3;j++){
			printf(" %c |",board[i][j]);
		}
		printf("\n");
	}
}
	
int check_win(char board[3][3]){
	if((board[0][0] == 'x')&&(board[0][1] == 'x')&&(board[0][2] == 'x')){
		return 1;
	}else if((board[1][0] == 'x')&&(board[1][1] == 'x')&&(board[1][2] == 'x')){
		return 1;
	}else if((board[2][0] == 'x')&&(board[2][1] == 'x')&&(board[2][2] == 'x')){
		return 1;
	}else if((board[0][0] == 'x')&&(board[1][0] == 'x')&&(board[2][0] == 'x')){
		return 1;
	}else if((board[0][1] == 'x')&&(board[1][1] == 'x')&&(board[2][1] == 'x')){
		return 1;
	}else if((board[0][2] == 'x')&&(board[1][2] == 'x')&&(board[2][2] == 'x')){
		return 1;
	}else if((board[0][0] == 'x')&&(board[1][1] == 'x')&&(board[2][2] == 'x')){
		return 1;
	}else if((board[0][2] == 'x')&&(board[1][1] == 'x')&&(board[2][0] == 'x')){
		return 1;
	}else if((board[0][0] == 'o')&&(board[0][1] == 'o')&&(board[0][2] == 'o')){
		return 1;
	}else if((board[1][0] == 'o')&&(board[1][1] == 'o')&&(board[1][2] == 'o')){
		return 1;
	}else if((board[2][0] == 'o')&&(board[2][1] == 'o')&&(board[2][2] == 'o')){
		return 1;
	}else if((board[0][0] == 'o')&&(board[1][0] == 'o')&&(board[2][0] == 'o')){
		return 1;
	}else if((board[0][1] == 'o')&&(board[1][1] == 'o')&&(board[2][1] == 'o')){
		return 1;
	}else if((board[0][2] == 'o')&&(board[1][2] == 'o')&&(board[2][2] == 'o')){
		return 1;
	}else if((board[0][0] == 'o')&&(board[1][1] == 'o')&&(board[2][2] == 'o')){
		return 1;
	}else if((board[0][2] == 'o')&&(board[1][1] == 'o')&&(board[2][0] == 'o')){
		return 1;
	}else{
		return 0;
	}
}

int do_draw(const char board[3][3]){
	if((board[0][0]!='-')&&(board[0][1]!='-')&&(board[0][2]!='-')&&(board[1][0]!='-')&&(board[1][1]!='-')&&(board[1][2]!='-')&&(board[2][0]!='-')&&(board[2][1]!='-')&&(board[2][2]!='-')){
		return 1;
	}else{
		return 0;
	}
}







