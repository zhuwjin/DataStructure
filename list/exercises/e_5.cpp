#include <iostream>
#include "LiList.h"

void Reverse(LiList &L) {
    LiNode *p = nullptr, *q = L->next, *temp;
    while (q != nullptr) {
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    L->next = p;
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
    Reverse(l);
    std::cout << "反转后: ";
    PrintList(l);
    return 0;
}