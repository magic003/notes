#ifndef TRAVERSE_H
#define TRAVERSE_H
#include "graph.h"

typedef struct {
    void (*beforeProcess) (int v);
    void (*afterProcess) (int v);
    void (*onDiscovered) (int t, int s);
    void (*onProcessEdge) (int x, int y);
} TraverseListener;

void bfs(Graph* g, int start, TraverseListener* listener);

void dfs(Graph* g, int start, TraverseListener* listener);

#endif
