#include <stdlib.h>
#include "set_union.h"

SetUnion* newSetUnion(int n) {
    SetUnion* s = (SetUnion*) malloc(sizeof(SetUnion));

    s->n = n;
    s->parent = (int*) malloc((n+1) * sizeof(int));
    s->size = (int*) malloc((n+1) * sizeof(int));

    int i;
    for (i=0; i<=n; i++) {
        s->parent[i] = i;
        s->size[i] = 1;
    }

    return s;
}

int find(SetUnion* s, int x) {
    if (s->parent[x] == x) {
        return x;
    }
    return find(s, s->parent[x]);
}

void unions(SetUnion* s, int s1, int s2) {
    int r1, r2;

    r1 = find(s, s1);
    r2 = find(s, s2);

    if (r1 != r2) {
        if (s->size[r1] >= s->size[r2]) {
            s->size[r1] = s->size[r1] + s->size[r2];
            s->parent[r2] = r1;
        } else {
            s->size[r2] = s->size[r2] + s->size[r1];
            s->parent[r1] = r2;
        }
    }
}

int sameComponent(SetUnion* s, int s1, int s2) {
    return find(s, s1) == find(s, s2);
}

void deleteSetUnion(SetUnion* s) {
    if (s != NULL) {
        if (s->parent != NULL) free(s->parent);
        if (s->size != NULL) free(s->size);
        free(s);
    }
}
