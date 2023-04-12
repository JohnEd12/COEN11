#include <lab8.h>

void insert(char *n, int g){
        char names[20];
        NODE *p;
        int num;
        int j;
        p = (NODE*)malloc(sizeof(NODE));                                         
        strcpy(p->name, n);
        p->drinks = g;
        if(g < 3){
                j=0;
        }else if(g < 5){
                j=1;
        } else if (g <7){
                j=2;
        } else {
                j=3;
        }
        if(array[j].head == NULL){   
                array[j].head = p;
                array[j].tail = p;
        }else{ 
                array[j].tail->next= p;
                array[j].tail = p;
        }
}
void delete(){
        NODE *p, *w;
        int j;
        int i;
        int num1;

        printf("How many drinks does the group have that you wanna delete?\n");
        scanf("%d",&num1);
        if(num1<3){
                i=1;
        } else if (num1<5){
                i=2;
        } else if (num1<7){
                i=3;
        } else {
                i=4;
        }
        for(j = 0; j <= i; j++){
                p=w= array[j].head;
                while(p != NULL){
                        if(p->drinks <= num1){
                                num1-=p->drinks;
                                 if(p == array[j].head){
                                        array[j].head = array[j].head->next;
                                }else if(p->next != NULL){ 
                                        w->next= p->next;
                                }else{ 
                                        w->next = NULL;
                                        array[i].tail = w;
                                }
                                w->next = p->next;
                                free(p);
                        }
                        w=p;
                        p=p->next;
                }
        }
        return;
}
void drink_orders(){
        int i;
        int M;
        int drinkO;
        NODE *p;
        printf("What drink oders  would you like to see?, example if you want to see drink orders that have 5 drinks or less, please enter 5\n");
        scanf("%d",&drinkO);
        if(drinkO<3){
                M=1;
        } else if (drinkO<5){
                M=2;
        } else if (drinkO<7){
                M=3;
        } else {
                M=4;
        }
        for(i = 0; i < M; i++){
                p = array[i].head;
                while(p != NULL){
                        if(p->drinks <= drinkO){
                                printf("%s,%d\n",p->name, p->drinks);
                        }
                p = p->next;
                }
        }
        return;
}
int dup(char *s){
        NODE *p;
        int j;
        for(j = 0; j < N; j++){
                p = array[j].head;
                while(p != NULL){
                        if(strcmp(p->name,s) == 0){
                                return 1;
                        }
                        p = p->next;
                }
        }
        return 0;
}

