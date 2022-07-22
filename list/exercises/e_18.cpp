#include <iostream>
#include "CLinklist.h"

void Link(CLinklist &h1, CLinklist &h2) {
    CNode *p = h1, *q;
    while (p->next != h1) {
        p = p->next;
    }
    if (!Empty(h1)) {
        q = h2->next;
        h2->next = h1->next;
        p->next = q;
    }
    h1 = h2;
}

int main() {
    CLinklist l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 2, 2);
    ListInsert(l1, 3, 3);
    CLinklist l2;
    InitList(l2);
    ListInsert(l2, 1, 4);
    ListInsert(l2, 2, 5);
    ListInsert(l2, 3, 6);
    ListInsert(l2, 4, 7);
    std::cout << "l1: ";
    PrintList(l1);
    std::cout << "l2: ";
    PrintList(l2);
    Link(l1, l2);
    std::cout << "链接后: ";
    PrintList(l1);
    return 0;
}