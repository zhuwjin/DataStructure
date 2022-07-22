#include <iostream>
#include "LiList.h"

int Search_K(LiList head, int k) {
    int t = k;
    LiNode *p = head, *q = head;
    while (p != nullptr && t > 0) {
        p = p->next;
        t -= 1;
    }
    if (p == nullptr) {
        return 0;
    }
    while (p != nullptr) {
        p = p->next;
        q = q->next;
    }
    std::cout << "倒数第" << k << "个结点值为: " << q->data << std::endl;
    return 1;
}

int main() {
    LiList l;
    InitList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    ListInsert(l, 4, 4);
    ListInsert(l, 5, 5);
    ListInsert(l, 6, 6);
    ListInsert(l, 7, 7);
    PrintList(l);
    Search_K(l, 1);
    return 0;
}