#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct posto { 
    int local;
    int capacidade;
} posto;

int main (){
    int N, M, H, T, I, C, P;
    scanf ("%d %d %d %d %d %d %d", &N, &M, &H, &T, &I, &C, &P);
    // inicialização dos postos
    posto postos[P];
    for(int i = 0; i < P; i++){
        scanf ("%d", &postos[i].local);
        postos[i].capacidade = INT_MAX;
    }
    // inicialização dos grafos
    return 0;
}

