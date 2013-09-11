#include <stdio.h>

#define MAX 15

int graph[MAX+1][MAX+1];

void initialGraph(int graph[][MAX+1]) {
    int i,j;
    for (i=0;i<MAX+1;i++) {
        for (j=0;j<MAX+1;j++) {
            graph[i][j] = 0;
        }
    }
}

void readGraph(int graph[][MAX+1], const char* file) {
    FILE* fp = fopen(file, "r");

    if (fp != NULL) {
        int x, y;
        // consume and ignore the number of vertices
        fscanf(fp, "%d\n", &x);
        while (fscanf(fp, "%d %d\n", &x, &y) != -1) {
            graph[x][y] = 1;
        }

        fclose(fp);
    }
}

void printGraph(int graph[][MAX+1]) {
    int i,j;

    for (i=0;i<MAX+1;i++) {
        for (j=0;j<MAX+1;j++) {
            if (graph[i][j] == 1) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    initialGraph(graph);

    readGraph(graph, "graph.txt");

    printGraph(graph);

    return 0;
}
