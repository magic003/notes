#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void printSolution(int* a, int k) {
    int i;
    for (i=0; i < k; i++) {
        printf("%d->", a[i]);
    }
    printf("%d\n", a[k]);
}

int candidates(int* a, int k, Graph* g, int* c, int* inpath) {
    Node* node = g->nodes[a[k]];
    int ncandidates = 0;
    while (node != NULL) {
        if (!inpath[node->label]) {
            c[ncandidates++] = node->label;
        }

        node = node->next;
    }

    return ncandidates;
}

void backtrace(int* a, int k, Graph* g, int s, int t, int* inpath) {
    if (a[k] == t) {
        printSolution(a, k);
    } else {
        int* c = (int*) malloc(g->nvertices * sizeof(int));
        int ncandidates = candidates(a, k, g, c, inpath);
        k += 1;
        int i;
        for (i=0; i < ncandidates; i++) {
            a[k] = c[i];
            inpath[c[i]] = 1;
            backtrace(a, k, g, s, t, inpath);
            inpath[c[i]] = 0;
        }

        free(c);

    }
}

void paths(Graph* g, int s, int t) {
    int* a = (int*) malloc(g->nvertices * sizeof(int)); // solution vector
    a[0] = s;

    int* inpath = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    for (i=0; i<= g->nvertices; i++) {
        inpath[i] = 0;
    }
    inpath[1] = 1;

    backtrace(a, 0, g, s, t, inpath);

    free(inpath);
    free(a);
}

int main(int argc, char* argv[]) {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    paths(g, 1, 3);

    deleteGraph(g);

    return 0;
}
