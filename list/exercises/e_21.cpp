#include <iostream>
#include "LiList.h"

LiNode *FindLoopStart(LiList L) {
    LiNode *p = L->next, *q = L->next;
    while (q != nullptr && q->next != nullptr) {
        p = p->next;
        q = q->next->next;
        if (p == q) {
            break;
        }
    }
    if (q == nullptr || q->next == nullptr) {
        return nullptr;
    }
    p = L->next;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}


int main() {
    LiList l;
    InitList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    ListInsert(l, 4, 4);
    ListInsert(l, 5, 5);
    auto a = GetElem(l, 5);
    a->next = GetElem(l, 3);
    auto b = FindLoopStart(l);
    return 0;
}