#include <stdio.h>
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


int main() {
    
    int i;

    ArrayList L = { 
    {
        {"Neil", 'A',"Chu"},
        {"Kim", 'C', "Kol"},
        {"Jay", 'B', "Lim"},
        {"Gong", 'D', "Sin"},
        {"Lee", 'E', "Zha"}
    },
    5
    };

    L.count++;
    
    for(i=L.count-1; i >= 0 && strcmp(L.names[i].Lname,"Nom") > 0; i--)
    {
      
       strcpy(L.names[i+1].Lname, L.names[i].Lname);
      
        
       }
        strcpy(L.names[i+1].Lname, "Nom"); 
    
    

    for(i=0; i<L.count; i++)
        printf("\n%s", L.names[i].Lname);
        
        
        
    }