#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

typedef struct {
    int** weights;
    int nvertices;
} Graph;

Graph* newGraph();

void loadGraph(Graph* g, const char* filename);

void deleteGraph(Graph* g);

#endif
