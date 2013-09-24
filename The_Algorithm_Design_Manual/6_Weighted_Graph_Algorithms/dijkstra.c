#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

static void printPath(int parent[], int s, int t) {
    if ( s == t || t == -1) {
        printf("%d", s);
    } else {
        printPath(parent, s, parent[t]);
        printf("->%d", t);
    }
}

int dijkstra(Graph* g, int s, int t) {
    int* intree;
    int* distance;
    int* parent;

    intree = (int*) malloc((g->nvertices+1) * sizeof(int));
    distance = (int*) malloc((g->nvertices+1) * sizeof(int));
    parent = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0; i<=g->nvertices; i++) {
        intree[i] = 0;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    int v = s;
    distance[s] = 0;

    while ( v != t) {
        intree[v] = 1;
        EdgeNode* e = g->edges[v];

        while ( e != NULL) {
            int y = e->y;
            if (!intree[y] && distance[y] > distance[v] + e->weight) {
                distance[y] = distance[v] + e->weight;
                parent[y] = v;
            }
            
            e = e->next;
        }

        int i;
        int dist = INT_MAX;
        for ( i = 1; i <= g->nvertices; i++) {
            if (!intree[i] && dist > distance[i]) {
                dist = distance[i];
                v = i;
            }
        }
    }

    printf("Shortest path: ");
    printPath(parent, s, t);
    printf("\n");

    return distance[t];
}

int main(int argc, char* argv[]) {
    Graph* g = newGraph(1);

    loadGraph(g, "shortest_path.txt");

    int dist = dijkstra(g, 1, 6);

    printf("Distance: %d\n", dist);

    deleteGraph(g);

    return 0;
}
