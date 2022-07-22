#include <iostream>
#include "LiList.h"

void Clean(LiList &L, int n) {
    bool nums[n + 1];
    for (int i = 0; i < n + 1; i++) {
        nums[i] = false;
    }
    LiNode *p = L, *del_node;
    while (p->next != nullptr) {
        if (nums[abs(p->next->data)]) {
            del_node = p->next;
            p->next = del_node->next;
            delete del_node;
        } else {
            nums[abs(p->next->data)] = true;
            p = p->next;
        }
    }
}

int main() {
    LiList l;
    InitList(l);
    int nums[] = {21, -15, -15, -7, 15};
    for (int i = 0; i < 5; i++) {
        ListInsert(l, i + 1, nums[i]);
    }
    PrintList(l);
    Clean(l, 21);
    PrintList(l);
    return 0;
}