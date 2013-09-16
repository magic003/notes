#include "graph.h"

int main(int argc, char* argv[]) {
    Graph* g = newGraph(0);

    loadGraph(g, "graph.txt");

    printGraph(g);

    deleteGraph(g);

    return 0;
}
