#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int random_choice(){
	srand(time(NULL));
	int choice = rand()%3;
	if(choice==2){
		return 'r'; //rock
	}
	else if(choice==1){
		return 'p'; //paper
	}
	else{
		return 's'; //scissors
	}
	return 0;
}
void main(){
	int score = 0;
	while(true){
		system("clear");
		if(score<=0){
			score=0;
		}
		char choice;
		printf("score: %d",score);
		printf("\nrock, paper, scissors [r/p/s] >> ");scanf(" %c",&choice);
		switch(choice){
			case('r'):
				if(random_choice()=='r'){
					printf("tie\n");
				}
				else if(random_choice()=='p'){
					printf("loss\n");
					score--;
				}
				else if(random_choice()=='s'){
					printf("win\n");
					score++;
				}
				break;
			case('p'):
				if(random_choice()=='r'){
					printf("win\n");
					score++;
				}
				else if(random_choice()=='p'){
					printf("tie\n");
				}
				else if(random_choice()=='s'){
					printf("loss\n");
					score--;
				}
				break;
			case('s'):
				if(random_choice()=='r'){
					printf("loss");
					score--;
				}
				else if(random_choice()=='p'){
					printf("win");
					score++;
				}
				else if(random_choice()=='s'){
					printf("tie");
				}
				break;
			case('e'):
				exit(1);
			default:
				printf("INVALID\n");
				break;
		}
		sleep(1);
	}
}
