#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "set_union.h"

typedef struct {
    int x;
    int y;
    int weight;
} Edge;

static int partition(Edge** edges, int start, int end) {
    Edge* pivot = edges[end];

    int i, next;
    for (i=start, next=start; i < end; i++) {
        if (edges[i]->weight <= pivot->weight) {
            Edge* tmp = edges[i];
            edges[i] = edges[next];
            edges[next] = tmp;
            next++;
        }
    }

    edges[end] = edges[next];
    edges[next] = pivot;

    return next;
}

static void quicksort(Edge** edges, int start, int end) {
    if (start < end) {
        int pivot = partition(edges, start, end);

        quicksort(edges, start, pivot-1);
        quicksort(edges, pivot+1, end);
    }
}

static Edge** sortEdges(Graph* g, int* n) {
    *n = g->nedges;
    if (!g->directed) {
        *n /= 2;
    }

    Edge** edges = (Edge**) malloc(*n * sizeof(Edge*));

    int i,j;
    for (i=1, j=0; i <= g->nvertices; i++) {
        EdgeNode* en = g->edges[i];
        while (en != NULL) {
            if (en->y > i) {
                Edge* e = (Edge*) malloc(sizeof(Edge));
                e->x = i;
                e->y = en->y;
                e->weight = en->weight;
                edges[j++] = e;
            }
            en = en->next;
        }
    }

    quicksort(edges, 0, *n-1);

    return edges;
}

void kruskal(Graph* g) {
    SetUnion* s = newSetUnion(g->nvertices);

    int n;
    Edge** edges = sortEdges(g,&n);

    printf("Minimum Spanning Tree: \n");
    int i;
    for (i = 0; i < n; i++) {
        Edge* e = edges[i];
        if (!sameComponent(s, e->x, e->y)) {
            printf("%d %d: %d\n", e->x, e->y, e->weight);
            unions(s, e->x, e->y);
        }
    }

    deleteSetUnion(s);
}

int main(int argc, char* argv[]) {
    Graph* g = newGraph(0);

    loadGraph(g, "mst.txt");

    kruskal(g);

    deleteGraph(g);
    return 0;
}
