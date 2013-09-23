#ifndef SET_UNION_H
#define SET_UNION_H

typedef struct {
    int* parent;    // parent of each element
    int* size;      // size of the subtree
    int n;          // number of elements
} SetUnion;

SetUnion* newSetUnion(int n);

int find(SetUnion* s, int x);

void unions(SetUnion* s, int s1, int s2);

int sameComponent(SetUnion* s, int s1, int s2);

void deleteSetUnion(SetUnion* s);
#endif
