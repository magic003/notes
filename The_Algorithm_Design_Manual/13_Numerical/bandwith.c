#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "queue.h"

void bandwidth(Graph* g, int* result) {
    int* degree = (int*) malloc((g->nvertices+1) * sizeof(int));
    int* visit = (int*) malloc((g->nvertices+1) * sizeof(int));
    int i;
    int min = 1;
    for(i=1; i<=g->nvertices; i++) {
        visit[i] = 0;

        int size = 0;
        Node* node = g->nodes[i];
        while(node != NULL) {
            size++;
            node = node->next;
        }
        degree[i] = size;
        if (degree[min] > size) {
            min = i;
        }
    }

    Queue* q = newQueue(g->nvertices);
    enqueue(q, min);
    int ri = 0;

    while (!emptyQueue(q)) {
        int v = dequeue(q);
        if (!visit[v]) {
            visit[v] = 1;
            result[ri++] = v;
            // sort the edge by the other vertex's degree
            if (g->nodes[v] != NULL) {
                Node* head = g->nodes[v]->next;
                g->nodes[v]->next = NULL;
                while (head != NULL) {
                    Node* prev = NULL;
                    Node* current = g->nodes[v];
                    while (current != NULL) {
                        if (degree[current->label] <= degree[head->label]) {
                            prev = current;
                            current = current->next;
                        } else {
                            break;
                        }
                    }

                    if (current == NULL) {
                        prev->next = head;
                        head = head->next;
                        prev->next->next = NULL;
                    } else {
                        if (prev == NULL) {
                            g->nodes[v] = head;
                            head = head->next;
                            g->nodes[v]->next = current;
                        } else {
                            prev->next = head;
                            head = head->next;
                            prev->next->next = current;
                        }
                    }
                }
            }

            Node* node = g->nodes[v];
            while (node != NULL) {
                if (!visit[node->label]) {
                    enqueue(q,node->label);
                }
                node = node->next;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    Graph* g = newGraph(0);
    loadGraph(g, "graph.txt");

    int* result = (int*) malloc(g->nvertices * sizeof(int));

    bandwidth(g,result);

    printf("Bandwidth: ");
    int i;
    for(i=0; i<g->nvertices; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    deleteGraph(g);
    return 0;
}
