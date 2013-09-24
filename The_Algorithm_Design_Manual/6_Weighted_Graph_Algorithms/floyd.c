#include <stdio.h>
#include <limits.h>
#include "adjacency_matrix.h"

void floyd(Graph* g) {
    int k,i,j;

    for (k=1; k <= g->nvertices; k++) {
        for (i=1; i <= g->nvertices; i++) {
            for (j=1; j <= g->nvertices; j++) {
                int throughk = 
                    (g->weights[i][k] == INT_MAX || g->weights[k][j] == INT_MAX) ? INT_MAX : g->weights[i][k] + g->weights[k][j];
                if (throughk < g->weights[i][j]) {
                    g->weights[i][j] = throughk;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    Graph* g = newGraph();

    loadGraph(g, "shortest_path.txt");

    floyd(g);

    printf("Shortest path from %d to %d: %d\n", 1, 6, g->weights[1][6]);

    deleteGraph(g);

    return 0;
}
