#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int score = 0;
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
int win(){
	printf("win\n");
	score++;
	return 0;
}
int tie(){
	printf("tie\n");
	return 0;
}
int loss(){
	printf("loss\n");
	score--;
	return 0;
}
void main(){
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
					tie();
				}
				else if(random_choice()=='p'){
					loss();
				}
				else if(random_choice()=='s'){
					win();
				}
				break;
			case('p'):
				if(random_choice()=='r'){
					win();
				}
				else if(random_choice()=='p'){
					tie();
				}
				else if(random_choice()=='s'){
					loss();
				}
				break;
			case('s'):
				if(random_choice()=='r'){
					loss();
				}
				else if(random_choice()=='p'){
					win();
				}
				else if(random_choice()=='s'){
					tie();
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
