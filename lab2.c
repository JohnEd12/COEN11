#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define SIZE 20
#define maxsize 10
//const int maxsize = 10;
int currentsize = 0;
char names [maxsize][SIZE];
int groupsize [maxsize];


void insert(void);
void removeRes(void);
void list(void);

int main(void){
	int i;
	int numbers;
	for(i = 0; i<maxsize; i++){
		groupsize[i] = 0;
		names[i][0] = '\0';
	}
	while(1){
		printf("to get on wait list, type 1. To remove an old entry type 2. To see the list type 3. To quit type 0.\n");
		scanf("%d", &numbers);
		switch(numbers){

			case(1):
				insert();
				break;

			case(2):
				removeRes();
				break;
			case(3):
				list();
				break;
			case(0):
				return 0;
		}
	
	}

}

void insert(void){
	if(currentsize < maxsize){
		char name [20];
		int group;
		int i = 0;
		printf("What is your name?\n");
		scanf("%s", name);
		while(i < currentsize){
			 if(strcmp(name,names[i]) != 0){
				i++;			
			}
			else{
				printf("that name is already taken.\n");
				return;
			}
		}
	printf("What is size of the reservation group?\n");
	scanf("%d",&group);
	while(group < 1){
			printf("Use a valid size for reservation group.\n");
			scanf("%d",&group);
	}
		strcpy(names[currentsize],name);
		groupsize[currentsize] = group;
		currentsize++;
		printf("You have successfully put yourself on the wait list.\n");
	}
	else{
		printf("Waitlist is full.\n");
	}
	return;
}
void removeRes(void){
	int i;
	int j;
	int slotsleft;
	printf("how big is the opening size?\n");
	scanf("%d", &slotsleft);
	for(i = 0; i < currentsize; i++){
		if(slotsleft >= groupsize[i]){
			printf("%s with groupsize %d has been successfully placed on a reservation and is now removed from waitlist.\n",names[i],groupsize[i]);
			slotsleft -= groupsize[i];
			for(j=i+1;j<currentsize;j++){
				groupsize[j-1] = groupsize[j];
				strcpy(names[j-1],names[j]);
			}
			groupsize[currentsize] = 0;
			names[currentsize][0] = '\0';
			i--;
			currentsize --;
		}
		if(!slotsleft)
			return;
	
	}
	return;
}

void list(void){
	int i;
	for(i=0;i<currentsize;i++){
		printf("The number %d slot is waitlisted by %s with group size %d.\n", i+1 ,names[i], groupsize[i]);
	}
	while(i < maxsize){
		printf("The number %d slot in waitlist is free.\n",i+1);
		i++;
	}
	return;
}

// 1. The output is an error, you can prevent this by making an if statement and telling the costumer to say a shorter name
// 2. My program can handle it by putting it on the list and putting it in the bototm as the newest input. 
// 3. You can use = 'true' or = 'false' and set those as 0's and 1's 
