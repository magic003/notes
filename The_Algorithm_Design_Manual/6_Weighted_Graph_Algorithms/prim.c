#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "graph.h"

int* parent;

void prim(Graph* g, int start) {
    int* intree;
    int* distance;

    intree = (int*) malloc(sizeof(int) * (g->nvertices+1));
    distance = (int*) malloc(sizeof(int) * (g->nvertices+1));
    int i;
    for (i = 0; i <= g->nvertices; i++) {
        intree[i] = 0;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    int v = start;
    distance[start] = 0;

    while (!intree[v]) {
        intree[v] = 1;

        EdgeNode* edge = g->edges[v];
        while (edge != NULL) {
            int y = edge->y;
            if (!intree[y] && distance[y] > edge->weight) {
                distance[y] = edge->weight;
                parent[y] = v;
            }

            edge = edge->next;
        }

        int dist = INT_MAX;
        int i;
        for (i=1; i<= g->nvertices; i++) {
            if (!intree[i] && dist > distance[i]) {
                dist = distance[i];
                v = i;
            }
        }
    }
}

Graph* init() {
    Graph* g = newGraph(0);

    loadGraph(g, "mst.txt");

    parent = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i = 0; i <= g->nvertices; i++) {
        parent[i] = -1;
    }

    return g;
}

int main(int argc, char* argv[]) {
    Graph* g = init();

    prim(g, 1);

    printf("Minimum spanning tree: \n");
    int i;
    for (i=1; i <= g->nvertices; i++) {
        printf("%d->%d\n",parent[i],i);
    }

    deleteGraph(g);

    return 0;
}
