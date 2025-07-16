#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct posto { 
    int local;
    int capacidade;
} posto;

typedef struct aresta {
    int vertice;
    aresta *prox;
    int peso;
} aresta;

typedef struct grafo {
    int V;
    int E;
    aresta *adj;
} grafo;

aresta *cria_aresta(int v, int peso) {
    aresta *nova_aresta = (aresta *)malloc(sizeof(aresta));
    nova_aresta->vertice = v;
    nova_aresta->prox = NULL;
    nova_aresta->peso = peso;
    return nova_aresta;
}

grafo *cria_grafo(int V) {
    grafo *g = (grafo *)malloc(sizeof(grafo));
    g->V = V;
    g->E = 0;
    g->adj = (aresta *)malloc(V * sizeof(aresta));
    for (int i = 0; i < V; i++) {
        g->adj[i].prox = NULL;
        g->adj[i].peso = 0;
    }
    return g;
}

void adiciona_aresta(grafo *g, int v, int w, int peso) {
    aresta *nova_aresta = cria_aresta(w, peso);
    nova_aresta->prox = g->adj[v].prox;
    g->adj[v].prox = nova_aresta;
    g->E++;
}

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

