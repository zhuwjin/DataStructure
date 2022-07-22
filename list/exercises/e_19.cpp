#include <iostream>
#include "CLinklist.h"

void Del_All(CLinklist &L) {
    CNode *min_prior_node, *p, *del_node;
    while (L->next != L) {
        min_prior_node = L;
        p = L;
        while (p->next != L) {
            if (p->next->data < min_prior_node->next->data) {
                min_prior_node = p;
            }
            p = p->next;
        }
        del_node = min_prior_node->next;
        min_prior_node->next = del_node->next;
        std::cout << del_node->data << " ";
        delete del_node;
    }
    delete L;
}

int main() {
    CLinklist l1;
    InitList(l1);
    ListInsert(l1, 1, 5);
    ListInsert(l1, 2, 1);
    ListInsert(l1, 3, 3);
    ListInsert(l1, 4, 19);
    ListInsert(l1, 5, 7);
    ListInsert(l1, 6, 9);
    ListInsert(l1, 7, 17);
    ListInsert(l1, 8, 2);
    ListInsert(l1, 9, 8);
    std::cout << "原链表: ";
    PrintList(l1);
    std::cout << "按从小到大依次删除: ";
    Del_All(l1);
    return 0;
}