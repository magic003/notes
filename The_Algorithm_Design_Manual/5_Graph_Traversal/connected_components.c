#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "traverse.h"

int* discovered;

Graph* init() {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    discovered = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0;i<=g->nvertices;i++) {
        discovered[i] = 0;
    }

    return g;
}

void onDiscovered(int t, int s) {
    discovered[t] = 1;
}

void beforeProcess(int v) {
    printf("%d ", v);
}

void connected_components(Graph* g) {
    int c = 0;
    int i;

    TraverseListener listener;
    listener.beforeProcess = beforeProcess;
    listener.afterProcess = NULL;
    listener.onDiscovered = onDiscovered;
    listener.onProcessEdge = NULL;

    for (i=1; i<= g->nvertices; i++) {
        if (!discovered[i]) {
            printf("Component %d: ", ++c);
            bfs(g, i, &listener);
            printf("\n");
        }
    }
}

int main(int argc, char* argv[]) {
    Graph* g = init();

    connected_components(g);

    return 0;
}
