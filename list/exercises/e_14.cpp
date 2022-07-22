#include <iostream>
#include "LiList.h"

LiList Get_Common(LiList A, LiList B) {
    LiList C;
    InitList(C);
    LiNode *a = A->next, *b = B->next, *c = C;
    while (a != nullptr && b != nullptr) {
        if (a->data == b->data) {
            c->next = new LiNode;
            c->next->data = a->data;
            c->next->next = nullptr;
            c = c->next;
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return C;
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
    LiList C = Get_Common(l1, l2);
    std::cout << "公共部分: ";
    PrintList(C);
    return 0;
}
