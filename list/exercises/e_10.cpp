#include <iostream>
#include "LiList.h"

LiList DisCreat_1(LiList &A) {
    LiList B;
    InitList(B);
    LiNode *p = A->next, *q = B;
    while (p != nullptr) {
        q->next = p->next;
        if (p->next != nullptr) {
            p->next = p->next->next;
        }
        q = q->next;
        p = p->next;
    }
    return B;
}

int main() {
    LiList l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 2, 2);
    ListInsert(l1, 3, 3);
    ListInsert(l1, 4, 4);
    ListInsert(l1, 5, 5);
    std::cout << "原链表: ";
    PrintList(l1);
    LiList l2 = DisCreat_1(l1);
    std::cout << "分解后: " << std::endl;
    std::cout << "l1: ";
    PrintList(l1);
    std::cout << "l2: ";
    PrintList(l2);
    return 0;
}