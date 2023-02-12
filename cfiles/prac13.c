#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char Fname[24];
    char Mi;
    char Lname[16];
}Nametype;

typedef struct node{
    Nametype name;
    struct node *link;
}nodetype, *nameList;

#define MAX 10
typedef struct{
    Nametype names[MAX];
    int count;
}ArrayList;

ArrayList declare(){
     ArrayList students = {
                            {
                              {"Neil", 'A', "Kei"},
                              {"Mum", 'K', "Nor"},
                              {"Yas", 'L', "Que"},
                              {"Bob", 'N', "Vegene"},
                              {"Kos", 'D', "Zar"},
                            }  ,
                               5
                         };
        return students;
}
void insert(ArrayList *nem,char *Fname, char Mi, char*Lname){
    
    int i;
    int space = nem->count-1;
    
    for(i=space; i>= 0 && strcmp(Lname, nem->names[i].Lname) < 0; i--){
       strcpy(nem->names[i + 1].Lname, nem->names[i].Lname);
}
       strcpy(nem->names[i + 1].Lname, Lname);
}
void display(ArrayList nem){

    int i;
    for(i = 0; i< nem.count+ 1; i++)
    printf("\n%s", nem.names[i].Lname);
}

int main(){
    
   ArrayList studname = declare();
    
    insert(&studname,"Jac",'K',"Apple");
    display(studname);
}