#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "traverse.h"

int* parent;

Graph* init() {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    parent = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0; i <= g->nvertices; i++) {
        parent[i] = -1;
    }

    return g;
}

void findPath(int from, int to, int* parent) {
    if (from == to || to == -1) {
        printf(" %d", from);
    } else {
        findPath(from, parent[to], parent);
        printf(" %d", to);
    }
}

void onDiscovered(int t, int s) {
    parent[t] = s;
}

void onProcessEdge(int x, int y) {
    if (parent[x] != y && parent[y] != x) {
        printf("Cycle from %d to %d: ", y, x);
        findPath(y, x, parent);
        printf("\n");
    }
}

void findCycles(Graph* g) {
    TraverseListener listener;
    listener.beforeProcess = NULL;
    listener.afterProcess = NULL;
    listener.onDiscovered = onDiscovered;
    listener.onProcessEdge = onProcessEdge;

    dfs(g, 1, &listener);

}

int main(int argc, char* argv[]) {
    Graph* g = init();

    findCycles(g);

    return 0;
}
