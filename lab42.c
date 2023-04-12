nclude <stdio.h>
#include <string.h>

#define SIZE 10
#define LENGTH 20

int counter=0;

typedef union {
	char phone_num[SIZE];
	int age;
	float avg_age;
}extra_info;

typedef struct {
	char names[LENGTH];
	int size;
	int max_age;
	extra_info info;
}waitlist;

waitlist q[SIZE];

void insert();
void delete();
void list();
void search_size();
int check_duplicate(char*);

int main(){
	int input;
	printf("Surf Lesson Options\n");
	printf("Option 1: Schedule Appointment\n");
	printf("Option 2: Remove Appointment\n");
	printf("Option 3: List Schedule\n");
	printf("Option 4: Search Size\n");
	printf("Option 0: Exit\n");
	
	while(1){
		printf("Please enter a command\n");
		scanf("%d", &input);
		
		switch(input) {
			case 1:
				insert();
				break;
			case 2: 
				delete();
				break;
			case 3: 
				list();
				break;
			case 4: 
				search_size();
				break;
			case 0: 
				printf("Quitting program\n");
				return 1;
				break;
			default: 
				printf("Bad option\n");
				break;
			
		}
	
	}
	return 0;

}

void insert() {
	int i;
	waitlist *p=q; //pointer to struct
	char userinput[20];	
	if (counter==10){						// checks to see if list is full
		printf("There is no more room on the list.\n");
	} else if (counter!=10){
		for (i=0; i<10; i++, p++){
			if(p->names[0]=='\0'){				// For loop traverses array, if checks for a \0 in position 0 (meaning the space is open) 
				printf("Please type in your name.\n");
				scanf("%s", &userinput);
				if((check_duplicate(userinput)==1)){		//checks for duplicate name. If its a duplicate, returns
					printf("That name is taken.\n");
					return;
				}
				strcpy(p->names, userinput);				// Asks for additional info
				printf("Please type in your group number.\n");
				scanf("%d", &p->size);
				printf("Please type in the max age of the person(s) in the group.\n");
				scanf("%d", &p->max_age);
				if(p->max_age<18){							// Checks age, and user inputs respective required information
					printf("Please type in the phone number of an adult.\n");
					scanf("%s", &p->info.phone_num);
				} else if (p->max_age>65){
					printf("Please type in the youngest age.\n");
					scanf("%d", &p->info.age);
				} else {
					printf("Please type in the average age of the group.\n");
					scanf("%f", &p->info.avg_age);
				}
				counter++;
				i=10;		// ends for loop
			}
		}
	}
	
}

void delete(){
	int i, x, temp, j, *temp2;
	waitlist *p=q;			//initializing pointer
	temp=counter;		
	if (counter==0){					// checks if there are names on the list
		printf("There are no groups to delete.\n");	
	} else if (counter!=0){
		printf("Type in the group size.\n");
		scanf("%d", &x);
		for(i=0; i<counter; i++, p++){
			if ((p->size)<=x){			// traveses list for first group <= inputted size
				x=x-(p->size);			// Subtracts size of group from input value so it can search again
				printf("%s's group for %d was removed.\n", p->names, p->size);
				for(j=i; j<counter-1; j++, p++){
					*p=*(p+1);				// shifts all structures up to fill deleted arrays
				}
				p-=(j+1);					//places pointer back at original position to avoid skipping a group
				i--;
				counter--;
			}
		}
	}
	if(counter==temp){
		printf("There are no groups small enough to delete.\n");
	}
}


void list(){
	int i;
	waitlist *p=q;			//initializing pointer
	if (counter==0){					// checks for groups
		printf("There are no names on the list.\n");
	} else if (counter!=0){
		printf("Position. Name, Group Number. Max Age, Extra Information\n");
		for(i=0; i<counter; i++, p++){								//for loop traverses up to the counter, outputting information in each structure
			printf("%d. %s, %d, \t Max age:%d, ", i+1, p->names, p->size, p->max_age);
			if(p->max_age<18){								// checks max age and prints corresponding addtional info
				printf("\tThe adult's phone number is: %s\n", p->info.phone_num);
			} else if (p->max_age>65){
				printf("\tThe min age is: %d\n", p->info.age);
			} else {
				printf("\tThe average age is: %f\n", p->info.avg_age);
			}
		
		}
	} 
}

void search_size(){
	int i, x, temp=0;
	waitlist *p=q;		//initializing pointer
	if (counter==0){
		printf("There are no groups on the waitlist.\n");
	} else {
		printf("Please type in the size you want to search for.\n");
		scanf("%d", &x);							// for loop traverses array for given group number, outputs any groups with group numbers <= input value
		for(i=0; i<counter; i++, p++){
			if((p->size)<=x){
				printf("%s's group has %d people.\n", p->names, p->size);
				temp=1;
			}
		}
	}
	if(temp==0){								//If no names were output, then the flag will tell this statement to print
		printf("There were no groups with that size.\n");
	}
	
}

int check_duplicate(char *name){
	int i, temp=0;
	waitlist *p=q;		//initializing pointer
	for(i=0; i<counter; i++, p++){			//traverses list and compares names with strcmp
		if(strcmp(p->names, name)==0){
			temp+=1;
			i=counter;
		}
	}
	if(temp==0){
		return 0;
	} else {
		return 1;
	}
}	

