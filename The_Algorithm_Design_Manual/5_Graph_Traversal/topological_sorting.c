#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "traverse.h"
#include "stack.h"

typedef enum { TREE, BACK, FORWARD, CROSS, UNKNOWN } EdgeKind;

Stack* stack;
int time;
int* discovered;
int* parent;
int* processed;
int* entry;

Graph* init() {
    Graph* g = newGraph(1);

    loadGraph(g, "DAG.txt");

    stack = newStack(g->nvertices);

    time = 0;

    discovered = (int*) malloc((g->nvertices+1) * sizeof(int));
    parent = (int*) malloc((g->nvertices+1) * sizeof(int));
    processed = (int*) malloc((g->nvertices+1) * sizeof(int));
    entry = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0; i <= g->nvertices; i++) {
        discovered[i] = 0;
        parent[i] = -1;
        processed[i] = 0;
        entry[i] = -1;
    }

    return g;
}

EdgeKind edgeKind(int x, int y) {
    if (parent[y] == x) return TREE;
    if (!processed[y] && discovered[y]) return BACK;
    if (processed[y] && entry[x] < entry[y]) return FORWARD;
    if (processed[y] && entry[y] < entry[x]) return CROSS;

    return UNKNOWN;
}

void beforeProcess(int v) {
    entry[v] = (++time);
}

void onDiscovered(int t, int s) {
    discovered[t] = 1;
    parent[t] = s;
}

void afterProcess(int v) {
    processed[v] = 1;
    push(stack, v);
}

void onProcessEdge(int x, int y) {
    EdgeKind ek = edgeKind(x, y);

    if (ek == BACK) {
        printf("It is not a DAG: %d %d\n", x, y);
    }
}

void topologicalSorting(Graph* g) {

    TraverseListener listener;
    listener.beforeProcess = beforeProcess;
    listener.afterProcess = afterProcess;
    listener.onDiscovered = onDiscovered;
    listener.onProcessEdge = onProcessEdge;

    int i;
    for (i=1; i <= g->nvertices; i++) {
        if (!discovered[i]) {
            dfs(g, i, &listener);
        }
    }

    printf("Topological sorting:");
    while (!emptyStack(stack)) {
        printf(" %d", pop(stack));
    }
    printf("\n");

}

int main(int argc, char* argv) {
    Graph* g = init();

    topologicalSorting(g);

    return 0;
}
