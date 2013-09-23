#ifndef GRAPH_H
#define GRAPH_H

typedef struct edgenode {
    int y;
    int weight;
    struct edgenode* next;
} EdgeNode;

typedef struct {
    EdgeNode** edges;
    int nvertices;
    int nedges;
    int directed;
} Graph;

Graph* newGraph(int directed);

void loadGraph(Graph* g, const char* filename);

void deleteGraph(Graph* g);

void printGraph(Graph* g);

#endif
