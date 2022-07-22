#include <iostream>
#include "LiList.h"

void Min_delete(LiList &head) {
    LiNode *min_prior_node, *curr_prior_node, *del_node;
    while (head->next != nullptr) {
        min_prior_node = curr_prior_node = head;
        while (curr_prior_node->next != nullptr) {
            if (curr_prior_node->next->data < min_prior_node->next->data) {
                min_prior_node = curr_prior_node;
            }
            curr_prior_node = curr_prior_node->next;
        }
        del_node = min_prior_node->next;
        min_prior_node->next = del_node->next;
        std::cout << del_node->data << " ";
        delete del_node;
    }
    delete head;
}


int main() {
    LiList l1;
    InitList(l1);
    ListInsert(l1, 1, 4);
    ListInsert(l1, 2, 2);
    ListInsert(l1, 3, 7);
    ListInsert(l1, 4, 5);
    ListInsert(l1, 5, -6);
    Min_delete(l1);
    return 0;
}
