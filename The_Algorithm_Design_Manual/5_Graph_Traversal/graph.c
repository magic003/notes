#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* newGraph(int directed) {
    Graph* g = malloc(sizeof(Graph));

    if (g == NULL) {
        printf("Not enough memory to create graph.\n");
    } else {
        g->nodes = NULL;
        g->nvertices = 0;
        g->nedges = 0;
        g->directed = directed;
    }

    return g;
}

void loadGraph(Graph* g, const char* file) {
    FILE* fp = fopen(file, "r");

    fscanf(fp, "%d\n", &(g->nvertices)); 

    g->nodes = (Node**) malloc((g->nvertices+1) * sizeof(Node*));
    int i;
    for (i=0;i<g->nvertices+1;i++) {
        g->nodes[i] = NULL;
    }

    int x, y;
    while ((fscanf(fp, "%d %d\n", &x, &y)) != -1) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->label = y;
        node->next = NULL;

        if (g->nodes[x] == NULL) {
            g->nodes[x] = node;
        } else {
            node->next = g->nodes[x];
            g->nodes[x] = node;
        }

        g->nedges++;
    }

    fclose(fp);
}

void deleteGraph(Graph* g) {
    if (g != NULL) {
        if (g->nodes != NULL) {
            int i;
            for (i=1;i<g->nvertices+1;i++) {
                Node* p = g->nodes[i];
                while (p!=NULL) {
                    Node* tmp = p;
                    p = p->next;
                    free(tmp);
                }
            }
            free(g->nodes);
        }
        free(g);
    }
}

void printGraph(Graph* g) {
    if (g != NULL) {
        int i;
        for (i=1;i<g->nvertices+1;i++) {
            Node* p = g->nodes[i];
            while (p!=NULL) {
                printf("(%d, %d)\n", i, p->label);
                p = p->next;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    printGraph(g);

    deleteGraph(g);

    return 0;
}
