#include <iostream>
#include "LiList.h"

LiNode *Search_1st_Common(LiList L1, LiList L2) {
    LiNode *p = L1, *q = L2;
    while (p != q) {
        p = p->next;
        q = q->next;
        if (p == nullptr) {
            p = L2;
        }
        if (q == nullptr) {
            q = L1;
        }
    }
    return p;
}


int main() {
    LiList l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 2, 2);
    ListInsert(l1, 3, 3);
    ListInsert(l1, 4, 4);
    ListInsert(l1, 5, 5);
    LiList l2;
    InitList(l2);
    ListInsert(l2, 1, 100);
    ListInsert(l2, 1, 200);
    ListInsert(l2, 1, 300);

    auto l1_2 = GetElem(l1, 2);
    auto l2_end = GetElem(l2, Length(l2));
    l2_end->next = l1_2;

    PrintList(l1);
    PrintList(l2);


    auto result = Search_1st_Common(l1, l2);
    std::cout << result << ":" << result->data;
    return 0;
}
