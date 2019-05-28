/*

* Author: Ian Cleaver, icleaver2018@my.fit.edu

* Course: CSE 1001, Section 02, Fall 2018

* Project: guessing

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void){

//Variable declaration

	int guess;
	int rand_num;
	char n;
	int numforcomp;

//Showing options

	do{
		printf("Choose a role to play: \n");
		printf("G: Guesser. Player will guess a number picked by the computer.\n");
		printf("S: Setter. The computer will try to guess a number picked by the player.\n");
		printf("Q: Quit.\n");
		printf("Enter your role: ");
		scanf(" %c",&n);
	
if((n=='G')||(n=='g')){
			printf("Try to guess a computer generated number between 1 and 100 inclusive.\n");
		
//Compute Random Number

			srand((unsigned) time(NULL));
			rand_num = (rand() % 100) + 1;
		
			printf("Number generated.\n");
		
//Game begins
		
			for(int i = 6;i>=0; i--){
				printf("What is your guess: ");
				scanf("%d",&guess);
				

//Code that runs if the user guesses correct
				
				if(guess==rand_num){
					printf("You guessed the number! Player wins!\n\n");
					i=0;
					break;
//code that runs if its out of the scope

				}else if((guess<0)||(guess>100)){
					i++;
					printf("The number you guessed is outside the range of 1 to 100 inclusive. You have %d guesses left. Choose another number.\n",i);
				
//Code run if user guesses wrong
					
				}else{
					printf("Your guess was wrong. You have %d guesses left.\n",i);
				}
				if(i==0){
					printf("Number was not guessed. Computer wins!\n\n");
				}
			}
		}	
	
//Code that runs if user inputs 'S' aka Setter
		
		if((n=='S')||(n=='s')){
			do{
			printf("Enter the number that the computer must guess: ");
			scanf("%d",&numforcomp);
			if((numforcomp>100)||(numforcomp<0)){
					printf("The number you guessed is outside the range of 1 to 100 inclusive. Choose another number.\n");
			}
			}while((numforcomp>100)||(numforcomp<0));
			
//Game Begins
			
			for(int i = 6;i>=0;i--){
				
//compute random number
				
				rand_num = (rand() % 100) + 1;
		
				printf("The computer guessed %d \n",rand_num);
				
//Code that runs if the rand_num variable matches the users input before 7 tries
				
				if(numforcomp==rand_num){
					printf("The guess is correct! Player loses.\n\n");
					i=0;
					break;
//Code that runs if the rand_num variable does not equal the users input after 7 tires
					
				}else{
					printf("The guess is incorrect. The computer has %d guesses left.\n",i);
				}if(i==0){
					printf("The computer did not guess the correct number. Player wins!\n\n");
				}
			}
			n=-1;
		}
	
	}while(!((n=='q')||(n=='Q')));	
return 0;
}




