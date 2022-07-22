#include <iostream>
#include "CDLinklist.h"

bool Symmetry(CDLinklist L) {
    CDNode *p = L->next, *q = L->prior;
    while (p != q && p -> next != q && p->data == q->data) {
        p = p->next;
        q = q->prior;
    }
    return p == q || p -> next == q;
}

int main() {
    CDLinklist l;
    InitList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 2);
    ListInsert(l, 4, 2);
    ListInsert(l, 5, 1);
    PrintList(l);
    auto a = Symmetry(l);
    std::cout << "l" << (a?"是":"不是") << "对称的" << std::endl;
    return 0;
}