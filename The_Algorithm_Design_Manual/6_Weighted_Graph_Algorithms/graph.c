#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* newGraph(int directed) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    
    if (g == NULL) {
        printf("Cannot create new graph because of out of memory.\n");
    } else {
        g->edges = NULL;
        g->nvertices = 0;
        g->nedges = 0;
        g->directed = directed;
    }

    return g;
}

void loadGraph(Graph* g, const char* filename) {
    FILE* fp = fopen(filename, "r");

    fscanf(fp, "%d\n", &g->nvertices);

    g->edges = (EdgeNode**) malloc((g->nvertices+1) * sizeof(EdgeNode*));
    int i;
    for (i = 0; i <= g->nvertices; i++) {
        g->edges[i] = NULL;
    }

    int x, y, w;
    while ((fscanf(fp, "%d %d %d\n", &x, &y, &w)) != -1) {
        EdgeNode* edge = g->edges[x];
        
        EdgeNode* newedge = (EdgeNode*) malloc(sizeof(EdgeNode));
        newedge->y = y;
        newedge->weight = w;
        newedge->next = NULL;

        if (edge == NULL) {
            g->edges[x] = newedge;
        } else {
            edge->next = newedge;
        }

        (g->nedges)++;
    }

    fclose(fp);
}

void deleteGraph(Graph* g) {
    if (g != NULL) {
        if (g->edges != NULL) {
            int i;
            for (i = 0; i <= g->nvertices; i++) {
                EdgeNode* edge = g->edges[i];
                while (edge != NULL) {
                    EdgeNode* tmp = edge;
                    edge = edge->next;

                    free(tmp);
                }
            }

            free(g->edges);
        }

        free(g);
    }
}

void printGraph(Graph* g) {
    if (g != NULL) {
        printf("Vertices: %d\n", g->nvertices);
        printf("Edges: %d\n", g->nedges);
        printf("\n");

        int i;
        for ( i = 0; i<= g->nvertices; i++) {
            EdgeNode* edge = g->edges[i];
            while (edge != NULL) {
                printf("%d %d %d\n", i, edge->y, edge->weight);
                edge = edge->next;
            }
        }
    }
}
