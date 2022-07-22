#include <iostream>
#include "LiList.h"

void Del_Same(LiList &L) {
    LiNode *p = L->next, *del_node;
    while (p->next != nullptr) {
        if (p->data == p->next->data) {
            del_node = p->next;
            p->next = del_node->next;
            delete del_node;
            continue;
        }
        p = p->next;
    }
}

int main() {
    LiList l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 2, 1);
    ListInsert(l1, 3, 3);
    ListInsert(l1, 4, 4);
    ListInsert(l1, 5, 4);
    ListInsert(l1, 6, 5);
    ListInsert(l1, 7, 6);
    std::cout << "原链表: ";
    PrintList(l1);
    Del_Same(l1);
    std::cout << "去重后: ";
    PrintList(l1);
    return 0;
}