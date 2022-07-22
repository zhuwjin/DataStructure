#include <iostream>
#include "LiList.h"

void ChangeList(LiList &L) {
    LiNode *p = L, *q = L, *r;
    while (q != nullptr && q->next != nullptr) {
        p = p->next;
        q = q->next->next;
    }
    r = p->next;
    p->next = nullptr;
    p = r;
    q = p->next;
    p->next = nullptr;
    while (q != nullptr) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    q = L->next;
    while (p != nullptr) {
        r = p->next;
        p->next = q->next;
        q->next = p;
        q = p->next;
        p = r;
    }
}

int main() {
    LiList l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 2, 2);
    ListInsert(l1, 3, 3);
    ListInsert(l1, 4, 4);
    ListInsert(l1, 5, 5);
    ListInsert(l1, 6, 6);
    ChangeList(l1);
    PrintList(l1);
    return 0;
}
