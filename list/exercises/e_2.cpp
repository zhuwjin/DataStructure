/**
* 02. 在带头节点的单链表L中，删除所有值为x的节点，并释放其空间，假设值为x的节点不唯一。
*/
#include <iostream>
#include "LiList.h"

void Del_X_2(LiList &L, ElemType e) {
    LiNode *prior_node = L;
    while (prior_node->next != nullptr) {
        LiNode *del_node = prior_node->next;
        if (del_node->data == e) {
            prior_node->next = del_node->next;
            delete del_node;
            continue;
        }
        prior_node = prior_node->next;
    }
}

int main() {
    LiList l;
    InitList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 2);
    ListInsert(l, 4, 3);
    ListInsert(l, 5, 2);
    std::cout << "原链表: ";
    PrintList(l);
    int del_num = 2;
    Del_X_2(l, del_num);
    std::cout << "删除所有" << del_num << "后的链表: ";
    PrintList(l);
    return 0;
}