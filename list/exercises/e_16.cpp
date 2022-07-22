#include <iostream>
#include "LiList.h"

bool Pattern(LiList A, LiList B) {
    LiNode *a = A->next, *b, *p;
    while (a != nullptr) {
        b = B->next;
        p = a;
        while (b != nullptr && p != nullptr && p->data == b->data) {
            p = p->next;
            b = b->next;
        }
        if (b == nullptr) {
            return true;
        }
        if (p == nullptr) {
            return false;
        }
        a = a->next;
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
    ListInsert(l2, 1, 3);
    ListInsert(l2, 2, 4);
    ListInsert(l2, 3, 5);
    std::cout << "l1: ";
    PrintList(l1);
    std::cout << "l2: ";
    PrintList(l2);
    std::cout << "l2" << (Pattern(l1, l2)?"是":"不是") << "l1的子串" << std::endl;
    return 0;
}