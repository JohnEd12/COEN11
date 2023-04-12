#include<lab8.h>

void read(char *filen){
        FILE *fp;
        if((fp = fopen(filen, "r")) == NULL){
                printf("Empty List.\n");
                return;
        }
        fseek(fp,24,SEEK_SET);
        char name[20];
        int drinkNum;
        int i;
        while(fscanf(fp,"%s\t%d",&name,&drinkNum) == 2){
                insert(name, drinkNum);
        }
        printf("Success.\n");
        list();
        fclose(fp);
        return;

}
void save(char *filen){
        FILE *fp;
        if((fp = fopen(filen, "w")) == NULL){
                printf("error\n");
                return;
        }
        fprintf(fp,"Name:     # of drinks:  \n");
        NODE *p;
        int i;
        for(i=0;i<4;i++){
                p = array[i].head;
                while(p != NULL){
                        fprintf(fp,"%s\t%d\n",p->name,p->drinks);
                        p = p->next;
                }
        }
        fclose(fp);
        return;
}

void backward_list(struct node *p ){
        if(p == NULL){
                return;
        }
        printf("%s\n", p->name);
        backward_list(p->next);
        return;
}
void free_L(int counter , struct node *p){
        int i;

        if(p->next != NULL){
                free_L(counter+1, p->next);
        }
        free(p);
        return;
}

