#include <lab8.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define N 6
#define NODE struct node
#define POINT struct point

// structure that has both a head and tail
struct point{
     NODE *head;
     NODE *tail;
};

// structure node
struct node{
	char name[20]; 
        int drinks;
        NODE *next;                            
};


POINT array[N];

void insert(char *name, int g);
void list();
void delete();
void drink_orders();
int dup(char *s);
void read(char *filen);
void save(char *filen);
void backward_list(struct node *p);
int num_orders(int count, struct node *p);
void free_L(int counter, struct node *p);

int main (int argc, char *argv[]){
        if(argc == 1){
                printf("file is missing\n");
                return 1;
        }
        int i;
        int counter = 0;
        int count=0;
        char name[20];
        int g;
        struct node *p;
        read(argv[1]);
        while (1) {
                printf("Welcome my bobashop\n");
                printf("type 0 to exit\n");
		printf("type 1 to reserve\n");
                printf("type 2 to delete\n");
                printf("type 3 to list\n");
                printf("type 4 to show people who ordered less than or equal to a certain number of drinks\n");
                printf("type 5 to print the list backwards\n");
                printf("type 6 to print the number of orders\n");
                int input;
                scanf("%d",&input);

                switch(input){
                        case 0:
                                save(argv[1]);
                                free_L(0,array[0].head);
                                return 1;
                        case 1:
                                printf("What is your name?\n");
                                scanf("%s", &name);
                                if(dup(name) == 1){
                                        printf("Name is already being used\n");
					break;
                                }
                                printf("How many drinks do you want?\n");
                                scanf("%d", &g);
                                insert(name, g);
                                printf("sucess\n");
                                break;
                        case 2:
                                delete();
                                break;
                        case 3:
                                list();
                                break;
                        case 4:
                                drink_orders();
                                break;
                        case 5:
                                printf("Backward List:\n");
                                for(i=N; i >=0; i--){
                                        p = array[i].head;
                                        backward_list(p);
                                }
                                break;
                        case 6:
                                printf("# of orders:\n");
                                p = array[i].head;
                                num_orders(count, p);
                                break;
                        default:
                                printf("Try again\n");
                                break;
                }
        }
}

