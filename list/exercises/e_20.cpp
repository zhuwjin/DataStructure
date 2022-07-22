#include <iostream>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *pred, *next;
    int freq;
} DNode, *DLinklist;

void InitList(DLinklist &L) {
    L = new DNode;
    L->pred = nullptr;
    L->next = nullptr;
}

DNode *GetElem(DLinklist L, int i) {
    if (i < 0) {
        return nullptr;
    } else {
        DNode *temp = L;
        while (i > 0) {
            temp = temp->next;
            i -= 1;
        }
        return temp;
    }
}

bool ListInsert(DLinklist &L, int i, ElemType e) {
    DNode *prior_node = GetElem(L, i - 1);
    if (prior_node == nullptr) {
        return false;
    } else {
        DNode *new_node = new DNode;
        new_node->data = e;
        new_node->pred = prior_node;
        new_node->next = prior_node->next;
        new_node->freq = 0;
        prior_node->next = new_node;
        if (new_node->next != nullptr) {
            new_node->next->pred = new_node;
        }
        return true;
    }
}

void PrintList(DLinklist L) {
    for (DNode *temp = L->next; temp != nullptr; temp = temp->next) {
        std::cout << temp->data << ":" << temp->freq << "\t";
    }
    std::cout << std::endl;
}

DNode *Locate(DLinklist &L, ElemType x) {
    DNode *p = L->next, *q;
    while (p != nullptr && p->data != x) {
        p = p->next;
    }
    if (p == nullptr) {
        return nullptr;
    }
    p->freq += 1;
    while (p->pred != L && p->pred->freq <= p->freq) {
        p->pred->next = p->next;
        if (p->next != nullptr) {
            p->next->pred = p->pred;
        }
        p->next = p->pred;
        p->pred = p->pred->pred;
        p->pred->next = p;
        p->next->pred = p;
    }
    return p;
}


int main() {
    DLinklist l;
    InitList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    ListInsert(l, 4, 4);
    ListInsert(l, 5, 5);
    ListInsert(l, 6, 6);
    ListInsert(l, 7, 7);
    ListInsert(l, 8, 8);
    PrintList(l);
    auto a = Locate(l, 5);
    PrintList(l);
    a = Locate(l, 4);
    PrintList(l);
    a = Locate(l, 5);
    PrintList(l);
    a = Locate(l, 8);
    PrintList(l);
    return 0;
}