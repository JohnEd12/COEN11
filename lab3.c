// John Edgar
//
//
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define maxsize 10
#define NODE struct node
#define LIST struct list

struct node{
	char name[20];
	int partysize;
	NODE *next;
};


struct list{
	NODE *head;
	NODE *tail; 
};
LIST array[4] ={{NULL,NULL}, {NULL,NULL}, {NULL,NULL}, {NULL, NULL}};

typedef struct waitlistperson{
	char names[20];
	int groupsize;
}RESSLOT;

RESSLOT slots [maxsize];
int currentsize = 0;

void insert(void);
int duplicatename(char *str);
void removeRes(void);
void list(void);
void listgroup(void);
 
//main func
int main(void){

	int i;
	char option;
	RESSLOT *personp = slots;
	for(i=0;i<maxsize;i++,personp++){
		personp->groupsize = 0;
		personp->names[0] = '\0';
	}
	printf("Welcome to boba shop II.\n");
	// case while statement
	while(1){
		printf("To add to wait list, type 1. To remove a  waitlist, type 2. To show the wait list, type 3. To show waitlists under a group size, type 4. To quit, type 0.\n");
		// scan func for switch 
		scanf(" %c",&option);
		switch(option){
			case '1':
				insert();
				break;
			case '2':
				removeRes();
				break;
			case '3':
				list();
				break;
			case '4':
				listgroup();
				break;
			case '0':
				return 0;
			default:
				printf("Please enter 1,2,3,4, or 0.\n");
		}
	}
}
// insert fucntion for option 1
void insert(void){

	RESSLOT *personp = slots;
	if(currentsize < maxsize){
		char name [20];
		int group;
		int i;
		printf("What is your name?\n");
		scanf("%s",name);
		i = duplicatename(name);
		if(i == 0)
			return;
		printf("What is size of the reservation group?\n");
		scanf("%d",&group);
		while(group < 1)
		{
			printf("Use a valid size for reservation group.\n");
			scanf("%d",&group);
		}
		personp += currentsize;
		strcpy(personp->names,name);
		personp->groupsize = group;
		currentsize++;
		printf("You have successfully put yourself on the wait list.\n");
		}
		else 
				printf("The waitlist is full. Try again later.\n");
			return;
}
// function that prevents a dulicate name from happening
int duplicatename(char *str){

	RESSLOT *personp = slots;
	int i=0;
	while(i<currentsize){

		if(strcmp(str,personp->names)!=0)
		{
			i++,personp++;
		}
		else
		{
			printf("The name is taken.\n");
			return 0;
		}
	}
	return 1;
}
// remove name
void removeRes(void){
	RESSLOT *personp = slots;
	RESSLOT *personq = slots;
	int i;
	int j;
	int slotsleft;
	printf("How big is the opening size?\n");
	scanf("%d",&slotsleft);
	for(i=0;i<currentsize;i++,personp++){
		if(slotsleft >=  personp->groupsize){
			printf("%s with groupsize %d has been successfully placed on a reservation and is now removed from waitlist.\n",personp->names,personp->groupsize);
			slotsleft -= personp->groupsize;
			for(j=i;j<currentsize-1;j++)
			{
				personq[j] = personq[j+1];
			}
			i--,personp--;
			currentsize --;
		}
		if(!slotsleft)
			return;
	}
	return;
}
// function to list the groups on the list
void list(void)
{
RESSLOT *personp = slots;
	int i;
	for(i=0;i<currentsize;i++,personp++){
		printf("The number %d slot is waitlisted by %s with group size %d.\n", i+1 ,personp->names, personp->groupsize);
	}	
	while(i < maxsize)
	{
		printf("The number %d slot in waitlist is free.\n",i+1);
		i++;
	}
	return;
}
// function to list the reservations that have a specific number of people in their group
void listgroup(void)
{
RESSLOT *personp = slots;
	int i;
	int constraint;
	printf("What is the largest group size you would like to list?\n");
	scanf("%d",&constraint);
	for(i=0;i<currentsize;i++,personp++)
	{
		if(personp->groupsize <= constraint)
			printf("The number %d slot is waitlisted by %s with group size %d.\n", i+1 ,personp->names, personp->groupsize);
	}
	return;
} 
