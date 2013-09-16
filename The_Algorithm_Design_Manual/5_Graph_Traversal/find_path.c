#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "traverse.h"
#include "queue.h"

int* parent;

Graph* init() {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    parent = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i = 0; i<=g->nvertices; i++) {
        parent[i] = -1;
    }

    return g;
}

void onDiscovered(int t, int s) {
    parent[t] = s;
}

void printTree(int* parent, int size) {
    int i;
    printf("Tree:\n");
    for (i=1; i<=size; i++) {
        if (parent[i] != -1) {
            printf("%d -> %d\n", parent[i], i);
        }
    }
}

void findPath(int start, int end, int* parent) {
    if ((start == end) || (end == -1)) {
        printf(" %d", start);
    } else {
        findPath(start, parent[end], parent);
        printf(" %d", end);
    }
}

int main(int argc, char* argv[]) {
    Graph* g = init();

    TraverseListener listener;
    listener.beforeProcess = NULL;
    listener.afterProcess = NULL;
    listener.onProcessEdge = NULL;
    listener.onDiscovered = onDiscovered;

    bfs(g, 1, &listener);

    printTree(parent, g->nvertices);

    int start = 1, end = 8;
    printf("Path %d -> %d: ", start, end);
    findPath(start, end, parent);
    printf("\n");

    return 0;
}

