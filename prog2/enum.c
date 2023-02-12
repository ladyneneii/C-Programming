#include <stdio.h>

typedef enum { 
    paper, scissors, rock
} Tooltype;

typedef enum { 
    P1wins, P2wins, DRAW
} Resulttype;

Resulttype game(int P1, int P2);

int main() {
    int P1tool, P2tool;
    
    printf("Enter 0, 1, or 2 for paper, scissors, and rock respectively.\n");
    printf("Player one:\n");
    scanf("%d", &P1tool);
    printf("Player two:\n");
    scanf("%d", &P2tool);
    
    if (game(P1tool, P2tool) == DRAW){
        printf("It is a draw.");
    } else if (game(P1tool, P2tool) == P1wins){
        printf("Player 1 won.");
    } else {
        printf("Player 2 won.");
    }

}

Resulttype game(int P1, int P2)
{
    Resulttype result;
    
    if (P1 == rock){
        switch(P2){
            case scissors: result = P1wins; break;
            case paper: result = P2wins; break;
            default: result = DRAW;
        }
    } else if (P1 == paper){
        switch(P2){
            case rock: result = P1wins; break;
            case scissors: result = P2wins; break;
            default: result = DRAW;
        }
    } else {
        switch(P2){
            case paper: result = P1wins; break;
            case rock: result = P2wins; break;
            default: result = DRAW;
        }
    }

    return result;
}