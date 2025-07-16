#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define vertex int
#define troca(a, b) { int t = a; a = b; b = t; }

static struct node *PQ;

typedef struct graph *Graph;
typedef struct node *link;

typedef struct posto { 
    int local;
    int capacidade;
} posto;

typedef struct restaurante {
    int local;
    int *pedidos;
}rest;

struct graph {
    int V;
    int A;
    link *adj;
};

struct node {
    vertex w;
    int custo;
    link next;
};


static link newNode ( vertex w, int custo, link next ) {
    link a = malloc ( sizeof (struct node) );
    a->w = w;
    a->custo = custo;
    a->next = next;
    return a;
}

Graph GraphInit ( int V ) {
    Graph G = malloc ( sizeof *G );
    G->V = V;
    G->A = 0;
    G->adj = malloc ( V * sizeof (link));
    for( vertex v = 0; v < V; ++v)
        G->adj[v] = NULL;
    return G;   
}   

void GraphInsertArc ( Graph G, vertex v, vertex w, int custo ) {
    for ( link a = G->adj[v]; a != NULL; a = a->next )
        if ( a->w == w ) return;
    G->adj[v] = newNode ( w, custo, G->adj[v] );
    G->A++;
}

void PQinit ( int V ) {
    // Inicializa a fila de prioridade
    PQ = malloc ( V * sizeof ( struct node ) );
}

void PQinsert ( vertex v, int *dist ) {
    // Insere o vértice v na fila de prioridade com a distância dist[v]
    
}

bool PQempty ( void ) {
    // Verifica se a fila de prioridade está vazia
    // (não implementada neste exemplo, mas necessária para o algoritmo de Dijkstra)
}

vertex PQdelmin ( int *dist ) {
    // Remove o vértice com a menor distância da fila de prioridade
    // (não implementada neste exemplo, mas necessária para o algoritmo de Dijkstra)
}

void PQdec ( vertex v, int *dist ) {
    // Decrementa a prioridade do vértice v na fila de prioridade
    // (não implementada neste exemplo, mas necessária para o algoritmo de Dijkstra)
}

void Dijkstra ( Graph G, vertex s, vertex *pa, int *dist)
{
   bool mature[1000];
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1, mature[v] = false, dist[v] = INT_MAX;
   pa[s] = s, dist[s] = 0;
   PQinit( G->V);
   for (vertex v = 0; v < G->V; ++v)
      PQinsert( v, dist);

   while (!PQempty( )) {
      vertex y = PQdelmin( dist);
      if (dist[y] == INT_MAX) break;
      // atualização de dist[] e pa[]:
      for (link a = G->adj[y]; a != NULL; a = a->next) {
         if (mature[a->w]) continue;
         if (dist[y] + a->custo < dist[a->w]) {
            dist[a->w] = dist[y] + a->custo;
            PQdec( a->w, dist);
            pa[a->w] = y;
         }
      }
      mature[y] = true;
   }
   PQfree( );
}

int main (){
    int N, M, H, T, I, C, P, Q;
    scanf ("%d %d %d %d %d %d %d", &N, &M, &H, &T, &I, &C, &P);
    // Estruturas necessárias
    Graph G = GraphInit(N);
    vertex pa[N];
    int dist[N];
    // inicialização dos postos
    posto postos[P];
    for (int i = 0; i < P; i++){
        scanf ("%d", &postos[i].local);
        postos[i].capacidade = INT_MAX;
    }
    // inicialização dos grafos
    for ( int i = 0; i < M; ++i ) {
        int v, w, custo;
        scanf("%d %d %d", &v, &w, &custo);
        GraphInsertArc (G, v, w, custo);
    }
    // inicialização dos restaurantes
    scanf("%d", &Q);
    rest restaurantes[Q];
    for (int i = 0; i < Q; ++i){
        int r, k;
        scanf("%d %d", &r, &k);
        restaurantes[i].local = r;
        restaurantes[i].pedidos = malloc(k * sizeof(int));
        for (int j = 0; j < k; ++j)
            scanf("%d", &restaurantes[i].pedidos[j]);
    }

    return 0;
}

