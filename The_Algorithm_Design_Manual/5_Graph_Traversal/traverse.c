#include <stdlib.h>
#include "traverse.h"
#include "queue.h"

static void run_bfs(Graph* g, int start, TraverseListener* listener, int* discovered, int* processed) {
    Queue* q = newQueue(g->nvertices);
    enqueue(q, start);
    discovered[start] = 1;

    while (!emptyQueue(q)) {
        int v = dequeue(q);
        if (listener->beforeProcess != NULL) {
            listener->beforeProcess(v);
        }

        Node* node = g->nodes[v];
        while (node != NULL) {
            int y = node->label;
            if (!discovered[y]) {
                enqueue(q, y);
                discovered[y] = 1;
                if (listener->onDiscovered != NULL) {
                    listener->onDiscovered(y, v);
                }
            } 
            if (!processed[y] || g->directed) {
                if (listener->onProcessEdge != NULL) {
                    listener->onProcessEdge(v, y);
                }
            }

            node = node->next;
        }

        processed[v] = 1;
        if (listener->afterProcess != NULL) {
            listener->afterProcess(v);
        }
    }
}

static void run_dfs(Graph* g, int start, TraverseListener* listener, int* discovered, int* processed) {
    Node* node = g->nodes[start];

    discovered[start] = 1;
    if (listener->beforeProcess != NULL) {
        listener->beforeProcess(start);
    }

    while (node != NULL) {
        int v = node->label;
        if (!discovered[v]) {
            discovered[v] = 1;
            if (listener->onDiscovered != NULL) {
                listener->onDiscovered(v, start);
            }
            if (listener->onProcessEdge != NULL) {
                listener->onProcessEdge(start, v);
            }
            run_dfs(g, v, listener, discovered, processed);
        } else if (!processed[v] || g->directed) {
            if (listener->onProcessEdge != NULL) {
                listener->onProcessEdge(start, v);
            }
        }

        node = node->next;
    }

    processed[start] = 1;
    if (listener->afterProcess != NULL) {
        listener->afterProcess(start);
    }
}

void bfs(Graph* g, int start, TraverseListener* listener) {
    int size = g->nvertices;

    int* discovered = (int*) malloc((size+1) * sizeof(int));
    int* processed = (int*) malloc((size+1) * sizeof(int));
    int i;
    for (i=0;i<size+1;i++) {
        discovered[i] = 0;
        processed[i] = 0;
    }

    run_bfs(g,start,listener,discovered,processed);

    free(discovered);
    free(processed);
}

void dfs(Graph* g, int start, TraverseListener* listener) {
    int size = g->nvertices;

    int* discovered = (int*) malloc((size+1) * sizeof(int));
    int* processed = (int*) malloc((size+1) * sizeof(int));
    int i;
    for (i=0;i<=size;i++) {
        discovered[i] = 0;
        processed[i] = 0;
    }

    run_dfs(g,start,listener,discovered,processed);

    free(discovered);
    free(processed);
}
