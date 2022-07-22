#include <iostream>
#include "LiList.h"

void MergeList(LiList &A, LiList &B) {
    LiNode *p, *a = A->next, *b = B->next;
    A->next = nullptr;
    while (a != nullptr && b != nullptr) {
        p = A->next;
        if (a->data < b->data) {
            A->next = a;
            a = a->next;
        } else {
            A->next = b;
            b = b->next;
        }
        A->next->next = p;
    }
    while (a != nullptr) {
        p = A->next;
        A->next = a;
        a = a->next;
        A->next->next = p;
    }
    while (b != nullptr) {
        p = A->next;
        A->next = b;
        b = b->next;
        A->next->next = p;
    }
}

int main() {
    LiList l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 2, 3);
    ListInsert(l1, 3, 4);
    ListInsert(l1, 4, 5);
    ListInsert(l1, 5, 9);
    LiList l2;
    InitList(l2);
    ListInsert(l2, 1, 2);
    ListInsert(l2, 2, 6);
    ListInsert(l2, 3, 7);
    ListInsert(l2, 4, 8);
    ListInsert(l2, 5, 10);
    std::cout << "l1: ";
    PrintList(l1);
    std::cout << "l2: ";
    PrintList(l2);
    MergeList(l1, l2);
    std::cout << "归并后: ";
    PrintList(l1);
    return 0;
}
