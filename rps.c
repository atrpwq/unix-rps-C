#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int score,aiscore=0;
int random_choice(){
	int choice = rand()%3;
	if(choice==0){
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
int win(),tie(),loss();
int chances(char,char,char);
void main(){
	char name[1024];
	printf("name >> ");fgets(name,1024,stdin);name[strlen(name)-1]='\0';
	while(true){
		srand(time(NULL));
		system("clear");
		if(score<=0){
			score=0;
		}
		if(aiscore<=0){
			aiscore=0;
		}
		char choice;
		printf("%s:%d\tai:%d",name,score,aiscore);
		printf("\nrock, paper, scissors [r/p/s] >> ");scanf(" %c",&choice);
		switch(choice){
			case('r'):
				chances('s','r','p');
				break;
			case('p'):
				chances('r','p','s');
				break;
			case('s'):
				chances('p','s','r');
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
int win(){
	printf("win\n");
	score++;
	aiscore--;
	return 0;
}
int tie(){
	printf("tie\n");
	return 0;
}
int loss(){
	printf("loss\n");
	score--;
	aiscore++;
	return 0;
}
int chances(char rps,char rps1, char rps2){
	if(random_choice()==rps){
		win();
	}
	else if(random_choice()==rps1){
		tie();
	}
	else{
		loss();
	}
}
