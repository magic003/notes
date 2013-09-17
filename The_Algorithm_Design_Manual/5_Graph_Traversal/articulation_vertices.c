#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "traverse.h"

typedef enum { TREE, BACK } EdgeKind;

int time;
int* reachableAncestor;
int* outDegree;
int* entry;
int* parent;

Graph* init() {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    time = 0;

    reachableAncestor = (int*) malloc((g->nvertices+1) * sizeof(int));
    outDegree = (int*) malloc((g->nvertices+1) * sizeof(int));
    entry = (int*) malloc((g->nvertices+1) * sizeof(int));
    parent = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0; i <= g->nvertices; i++) {
        reachableAncestor[i] = i;
        outDegree[i] = 0;
        entry[i] = -1;
        parent[i] = -1;
    }

    return g;
}

EdgeKind edgeKind(int x, int y) {
    if (entry[y] < 0) {
        return TREE;
    }

    return BACK;
}

void beforeProcess(int v) {
    reachableAncestor[v] = v;
    entry[v] = ++time;
}

void onDiscovered(int t, int s) {
    parent[t] = s;
}

void onProcessEdge(int x, int y) {
    EdgeKind ek = edgeKind(x, y);

    if (ek == TREE) {
        outDegree[x]++;
    } else {
        if (entry[y] < entry[reachableAncestor[x]]) {
            reachableAncestor[x] = y;
        }
    }        
}

int isRoot(int v) {
    return parent[v] == -1;
}

void afterProcess(int v) {
    
    // root cut node
    if (isRoot(v)) {
        if (outDegree[v] > 1) {
            printf("Root articulation vertex: %d\n", v);
        }
    } else if (reachableAncestor[v] == parent[v] && !isRoot(parent[v])) {
        printf("Parent articulation vertex: %d\n", parent[v]);
    } else if (reachableAncestor[v] == v) {
        printf("Bridge articulation vertex: %d\n", parent[v]);

        if (outDegree[v] > 0) {
            printf("Bridge articulation vertex: %d\n", v);
        }
    }

    int timeV = entry[reachableAncestor[v]];
    int timeParent = entry[reachableAncestor[parent[v]]];

    if (timeV < timeParent) {
        reachableAncestor[parent[v]] = reachableAncestor[v];
    }
}

int main(int argc, char* argv[]) {
    Graph* g = init();

    TraverseListener listener;
    listener.beforeProcess = beforeProcess;
    listener.afterProcess = afterProcess;
    listener.onDiscovered = onDiscovered;
    listener.onProcessEdge = onProcessEdge;

    dfs(g, 1, &listener);

    return 0;
}
