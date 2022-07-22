/**
 * 04. 试编写在头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）。
 * 用一个指针记录当前最小值的前结点的地址，然后遍历链表，如果遇到更小的就替换。
 */

#include <iostream>
#include "LiList.h"

void Del_Min(LiList &L) {
    LiNode *min_prior_node = L, *curr_prior_node = L;
    while (curr_prior_node->next != nullptr) {
        if (curr_prior_node->next->data < min_prior_node->next->data)
            min_prior_node = curr_prior_node;
        curr_prior_node = curr_prior_node->next;
    }
    if (min_prior_node->next != nullptr) {
        LiNode *min_node = min_prior_node->next;
        min_prior_node->next = min_node->next;
        delete min_node;
    }
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
    Del_Min(l);
    std::cout << "删除最小元素后: ";
    PrintList(l);
    return 0;
}