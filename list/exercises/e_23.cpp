#include <iostream>

typedef char ElemType;
typedef struct LiNode {
    ElemType data;
    struct LiNode *next;
} LiNode, *LiList;

LiNode *FindAddr(LiList L1, LiList L2) {
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
    LiList l1 = new LiNode;
    LiNode *p = l1, *q;
    char word1[] = "loading";
    for (int i = 0; word1[i] != '\0'; i++) {
        p->next = new LiNode{word1[i], nullptr};
        p = p->next;
    }
    q = l1->next->next->next->next->next;
    LiList l2 = new LiNode;
    p = l2;
    char word2[] = "be";
    for (int i = 0; word2[i] != '\0'; i++) {
        p->next = new LiNode{word2[i], nullptr};
        p = p->next;
    }
    p->next = q;
    auto a = FindAddr(l1, l2);
    return 0;
}
