#include <iostream>
#include "LiList.h"

void Union(LiList &A, LiList &B) {
    LiNode *a = A->next, *b = B->next, *p = A, *q;
    while (a != nullptr && b != nullptr) {
        if (a->data == b->data) {
            p->next = a;
            p = p->next;
            a = a->next;
            q = b;
            b = b->next;
            delete q;
        } else if (a->data < b->data) {
            q = a;
            a = a->next;
            delete q;
        } else {
            q = b;
            b = b->next;
            delete q;
        }
    }
    p->next = nullptr;
    while (a != nullptr) {
        q = a;
        a = a->next;
        delete q;
    }
    while (b != nullptr) {
        q = b;
        b = b->next;
        delete q;
    }
    delete B;
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
    ListInsert(l2, 2, 3);
    ListInsert(l2, 3, 4);
    ListInsert(l2, 4, 5);
    ListInsert(l2, 5, 10);
    std::cout << "l1: ";
    PrintList(l1);
    std::cout << "l2: ";
    PrintList(l2);
    Union(l1, l2);
    std::cout << "求交集后: ";
    PrintList(l1);
    return 0;
}