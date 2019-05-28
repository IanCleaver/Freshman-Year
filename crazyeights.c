/* 

*  Author: Ian Cleaver, icleaver2018@my.fit.edu       

*  Course: CSE 1001, Section 02, Fall 2018    

*  Project: crazyeights 

*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void deal_hand(int *in_deck, int *hand);
void reveal_card(int *arr_sub,int);
void set_deck(int *);
void set_hand(int *);
int do_playcard(int *);
void do_pass(int *,int *);
int play_card(int *,int,int *);

int main(void){
	int docounter=0;
	int count=0;
//Array holding the deck
	int stock[52];
//Array's holding each players hand
	int player1[52], player2[52];
//Setting all elements in arrays to 0, marking them as unused cards
		set_deck(stock);
		set_hand(player1);
		set_hand(player2);
//Dealing hand for each player
		deal_hand(stock,player1);
		deal_hand(stock,player2);
		printf("Starting Game...\n----------------------------------\n");

//Choosing random card to start game
		
	int starting_card =	do_playcard(stock);
//Show Random Card to be played upon
		
		printf("A Card has been Turned Over:\n");
	int start_card[52];
	for(int j=0;j<52;j++){
		start_card[j] = 1;
	}
	start_card[starting_card] = 0;
	docounter=0;
	reveal_card(start_card,docounter);
	
		printf("----------------------------------\n");

	int n;
	int verify;
	do{
//Player picks card from hand to play_card or passes
	printf("Player 1's Hand: \n");
//Reveal player 1 Hand
	docounter = 1;
	reveal_card(player1,docounter);
	printf("Player 1, Choose a Card to Play (-1 to Pass): ");
	scanf("%d",&n);
	printf("----------------------------------\n");
		//do{
			//printf("test");
			if(n==-1){
				do_pass(player1,stock);
				//printf("Player 1 Deck: \n");
				//reveal_card(player1);
			}else{
					verify = play_card(player1,n,start_card);
					while(verify==-1){
					//if(verify==0){
						//break;
					//if(verify==-1){
						//do{
							
						printf("Unvalid Card, please choose another option: ");
						scanf("%d",&n);
						if(n==-1){
								do_pass(player1,stock);
								break;
							}
						verify = play_card(player1,n,start_card);
						
						//}while(verify==-1);
						//printf("The card to play is: ");
						//docounter=0;
						//reveal_card(start_card,docounter);
					//}
					}
			}
		//}while(1==1);
	int condition=0;
			for(int x = 0;x<53;x++){
				if(x==52){
					printf("It's a Draw\n");
					condition=-1;
					break;
				}else if(stock[x]==0){
					break;
				}
			}
			for(int y=0;y<53;y++){
				if(y==52){
					printf("Player 1 Wins!!!\n");
					condition=-1;
					break;
				}else if(player1[y]==0){
					break;
				}
			}
			for(int t = 0;t<53;t++){
				if(t==52){
					printf("Player 2 Wins!!!\n");
					condition=-1;
					break;
				}else if(player2[t]==0){
					break;
				}
			}
		if(condition == -1){
			break;
		}
		
		//printf("----------------------------------\n");
		printf("The card to play is: ");
		docounter=0;
		reveal_card(start_card,docounter);
		printf("----------------------------------\n");

//player 2 picks card from hand to play_card or passes
		printf("Player 2's Hand: \n");
//Reveal player 1 Hand
	docounter=1;
	reveal_card(player2,docounter);
	printf("Player 2, Choose a Card to Play (-1 to Pass): ");
	scanf("%d",&n);
	printf("----------------------------------\n");
		//do{
			if(n==-1){
				do_pass(player2,stock);
				//printf("Player 1 Deck: \n");
				//reveal_card(player1);
			}else{
					verify = play_card(player2,n,start_card);
					while(verify==-1){
					//if(verify==0){
						//break;
					//if(verify==-1){
						//do{
							
						printf("Unvalid Card, please choose another option: ");
						scanf("%d",&n);
						if(n==-1){
								do_pass(player2,stock);
								break;
							}
						verify = play_card(player2,n,start_card);
						
						//}while(verify==-1);
						//printf("The card to play is: ");
						//docounter=0;
						//reveal_card(start_card,docounter);
					//}
					}
			}
		//}while(1==1);
			for(int x = 0;x<53;x++){
				if(x==52){
					printf("It's a Draw\n");
					condition=-1;
					break;
				}else if(stock[x]==0){
					break;
				}
			}
			for(int y=0;y<53;y++){
				if(y==52){
					printf("Player 1 Wins!!!\n");
					condition=-1;
					break;
				}else if(player1[y]==0){
					break;
				}
			}
			for(int t = 0;t<53;t++){
				if(t==52){
					printf("Player 2 Wins!!!\n");
					condition=-1;
					break;
				}else if(player2[t]==0){
					break;
				}
			}
		if(condition == -1){
			break;
		}
		//printf("----------------------------------\n");
		printf("The card to play is: ");
		docounter=0;
		reveal_card(start_card,docounter);
		printf("----------------------------------\n");

		
		}while(10==10);
		
		/*
		printf("Hand ");
		for(int i = 0;i<51;i++){
			printf(" %d ",player1[i]);
		}
		printf("\n");
		printf("Hand2");
		for(int i = 0;i<51;i++){
			printf(" %d ",player2[i]);
		}

	*/
return 0;	
}

void deal_hand(int in_deck[], int hand[]){
int rand_num;
srand((unsigned) time(NULL));

	for(int i = 0;i<5;i++){
	rand_num = (rand() % 50) + 1;
		if(in_deck[rand_num] == 0){
			hand[rand_num] = 0;
			in_deck[rand_num] = 1;
		}else{
			i--;
		}
	}
}

void reveal_card(int arr_sub[],int docounter){
int card;	
int x = 1;

	for(int i = 0;i<52;i++){
			card = i % 13;
		if(arr_sub[i]==0){
			if(docounter == 1){
				printf("%d. ",x);
				x++;
			}
			if((i<=12)&&(i>=0)){
				if(card==0){
					printf("Ace of Hearts\n");
				}else if((card<10)&&(card>0)){
					printf("%d of Hearts\n",card+1);
				}else if(card==10){
					printf("Jack of Hearts\n");
				}else if(card==11){
					printf("Queen of Hearts\n");
				}else if(card==12){
					printf("King of Hearts\n");
				}else{
					printf("Ian did bad");
				}
			}else if((i>=13)&&(i<=25)){
				if(card==0){
					printf("Ace of Diamonds\n");
				}else if((card<10)&&(card>0)){
					printf("%d of Diamonds\n",card+1);
				}else if(card==10){
					printf("Jack of Diamonds\n");
				}else if(card==11){
					printf("Queen of Diamonds\n");
				}else if(card==12){
					printf("King of Diamonds\n");
				}else{
					printf("Ian did bad");
				}
			}else if((i>=26)&&(i<=38)){
				if(card==0){
					printf("Ace of Clubs\n");
				}else if((card<10)&&(card>0)){
					printf("%d of Clubs\n",card+1);
				}else if(card==10){
					printf("Jack of Clubs\n");
				}else if(card==11){
					printf("Queen of Clubs\n");
				}else if(card==12){
					printf("King of Clubs\n");
				}else{
					printf("Ian did bad");
				}
			}else if((i>=39)&&(i<=51)){
				if(card==0){
					printf("Ace of Spades\n");
				}else if((card<10)&&(card>0)){
					printf("%d of Spades\n",card+1);
				}else if(card==10){
					printf("Jack of Spades\n");
				}else if(card==11){
					printf("Queen of Spades\n");
				}else if(card==12){
					printf("King of Spades\n");
				}else{
					printf("Ian did bad");
				}
			}
		}
	}
}

	
void set_deck(int array[]){
	for(int i = 0;i<52;i++){
	array[i] = 0;
	}	
}

void set_hand(int array[]){
	for(int i = 0;i<52;i++){
	array[i] = 1;
	}	
}

int do_playcard(int in_deck[]){
int rand_num;
int unvalid;

srand((unsigned) time(NULL));
	for(int i = 0;i<5;i++){
	rand_num = (rand() % 50) + 1;
	unvalid = rand_num % 13 + 1;
		if((in_deck[rand_num] == 0)&&(unvalid!=8)){
			in_deck[rand_num] = 1;
			return rand_num;
		}else{
			i--;
		}
	}
}

void do_pass(int hand[],int deck[]){
int rand_num;
srand((unsigned) time(NULL));	

do{
	rand_num = (rand() % 50) + 1;
	if(deck[rand_num]==0){
	hand[rand_num] = 0;
	deck[rand_num] = 1;
	break;
	}
}while(1!=-1);
}

int play_card(int hand[],int n,int play_card[]){
	int counter = 0;
	int card;
	int cardintable;
	int verify=-1;
		for(int j = 0;j<52;j++){
			if(play_card[j]==0){
				cardintable=j;
				
			}
		}
		for(int i = 0;i < 52;i++){
			card = i % 13;
			if(hand[i]==0){
				counter++;
			if(counter==n){
				if((cardintable<=12)&&(cardintable>=0)){
					if((card+1==8)||(card==cardintable%13)||(i<=12)&&(i>=0)){
						hand[i]=1;
						play_card[i]=0;
						verify = 0;
						play_card[cardintable]=1;
					}
				}else if((cardintable<=25)&&(cardintable>=13)){
					if((card+1==8)||(card==cardintable%13)||(i<=25)&&(i>=13)){
						hand[i]=1;
						play_card[i]=0;
						verify=0;
						play_card[cardintable]=1;
					}
				}else if((cardintable<=38)&&(cardintable>=26)){
					if((card+1==8)||(card==cardintable%13)||(i<=38)&&(i>=26)){
						hand[i]=1;
						play_card[i]=0;
						verify=0;
						play_card[cardintable]=1;
					}
				}else if((cardintable<=51)&&(cardintable>=39)){
					if((card+1==8)||(card==cardintable%13)||(i<=51)&&(i>=39)){
						hand[i]=1;
						play_card[i]=0;
						verify=0;
						play_card[cardintable]=1;
					}
				}
			}
			}
		}
		return verify;
	}













	
	
	
	
	
	
	
	
	
	
	
	
	