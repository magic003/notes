
#ifndef GRAPH_H
#define GRAPH_H

typedef struct node {
    int label;
    struct node* next;
} Node;

typedef struct {
    Node** nodes;
    int nvertices;
    int nedges;
    int directed;
} Graph;

Graph* newGraph(int directed);

void loadGraph(Graph* g, const char* file);

void deleteGraph(Graph* g);

void printGraph(Graph* g);

#endif
