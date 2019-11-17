#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vertex int
#define INFINITY 10000000

struct graph {
   int V;
   int A;
   int **adj;
};
typedef struct graph *Graph;

typedef struct node *link;
struct node {
   vertex w;
   int cst;
   link next;
};

vertex pa[1000];
int dist[1000];

void GRAPHsptD0( Graph G, vertex s)
{
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1;
   pa[s] = s, dist[s] = 0;

   while (true) {
      int min = INFINITY;
      vertex x, y;
      for (vertex v = 0; v < G->V; ++v) {
         if (pa[v] == -1) continue;
         for (link a = G->adj[v]; a != NULL; a = a->next) {
            if (pa[a->w] != -1) continue;
            if (dist[v] + a->cst < min) {
               min = dist[v] + a->cst;
               x = v, y = a->w;
            }
         }
      }
      if (min == INFINITY) // A
         break; // B
      pa[y] = x, dist[y] = min;
   }
}
