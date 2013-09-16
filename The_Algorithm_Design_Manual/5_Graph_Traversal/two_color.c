#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "traverse.h"

typedef enum { UNCOLORED, WHITE, BLACK } Color;

int* discovered;
Color* colors;

Graph* init() {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    colors = (Color*) malloc((g->nvertices+1) * sizeof(Color));
    discovered = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0; i <= g->nvertices; i++) {
        colors[i] = UNCOLORED;
        discovered[i] = 0;
    }


    return g;
}

Color complement(Color c) {
    if (c == WHITE) return BLACK;
    if (c == BLACK) return WHITE;

    return UNCOLORED;
}

void onDiscovered(int t, int s) {
    discovered[t] = 1;
    colors[t] = complement(colors[s]);
}

void onProcessEdge(int x, int y) {
    if (colors[x] == colors[y]) {
        printf("This is not a bipartite because of (%d, %d)\n", x, y);
    }
}

void twocolor(Graph* g) {
    TraverseListener listener;
    listener.beforeProcess = NULL;
    listener.afterProcess = NULL;
    listener.onDiscovered = onDiscovered;
    listener.onProcessEdge = onProcessEdge;

    int i;
    for (i=1; i<= g->nvertices; i++) {
        if (!discovered[i]) {
            colors[i] = WHITE;
            bfs(g, i, &listener);
        }
    }
}

int main(int argc, char* argv[]) {
    Graph* g = init();

    twocolor(g);

    return 0;
}
