#include <iostream>
#include "LiList.h"

void Sort(LiList &L) {
    LiNode *q = L->next, *r, *s;
    L->next = nullptr;
    while (q != nullptr) {
        r = q;
        q = q->next;
        s = L;
        while (s->next != nullptr && s->next->data < r->data)
            s = s->next;
        r->next = s->next;
        s->next = r;
    }
}


int main() {
    LiList l;
    InitList(l);
    ListInsert(l, 1, 7);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 4);
    ListInsert(l, 4, 3);
    ListInsert(l, 5, 5);
    std::cout << "原链表: ";
    PrintList(l);
    Sort(l);
    std::cout << "排序后: ";
    PrintList(l);
    return 0;
}