#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "adjacency_matrix.h"

Graph* newGraph() {
    Graph* g = (Graph*) malloc(sizeof(Graph));

    g->weights = NULL;
    g->nvertices = 0;

    return g;
}

void loadGraph(Graph* g, const char* filename) {
    FILE* fp = fopen(filename, "r");

    fscanf(fp, "%d\n", &g->nvertices);
    g->weights = (int**) malloc((g->nvertices+1) * sizeof(int*));
    int i;
    for (i = 0; i <= g->nvertices; i++) {
        g->weights[i] = (int*) malloc((g->nvertices+1) * sizeof(int));
        int j;
        for (j = 0; j <= g->nvertices; j++) {
            g->weights[i][j] = INT_MAX;
        }
    }

    int x,y,w;
    while (fscanf(fp, "%d %d %d\n", &x, &y, &w) != -1) {
        g->weights[x][y] = w;
    }

    fclose(fp);
}

void deleteGraph(Graph* g) {
    if (g != NULL) {
        if (g->weights != NULL) {
            int i;
            for (i = 0; i <= g->nvertices; i++) {
                free(g->weights[i]);
            }
            free(g->weights);
        }
        free(g);
    }
}
