#include <iostream>
#include "CLinklist.h"


void InitList(CLinklist &L) {
    L = new CNode;
    L->next = L;
}

int Length(CLinklist L) {
    int length = 0;
    for (CNode *temp = L->next; temp != L; temp = temp->next) {
        length += 1;
    }
    return length;
}

CNode *LocateElem(CLinklist L, ElemType e) {
    CNode *temp = L->next;
    while (temp != L && temp->data != e) {
        temp = temp->next;
    }
    return temp == L ? nullptr : temp;
}

CNode *GetElem(CLinklist L, int i) {
    if (i < 0) {
        return nullptr;
    }
    if (i == 0) {
        return L;
    }
    CNode *temp = L->next;
    for (int j = 1; j < i && temp != L; j++) {
        temp = temp->next;
    }
    return temp;
}

bool ListInsert(CLinklist &L, int i, ElemType e) {
    CNode *prior_node = GetElem(L, i - 1);
    if (prior_node == nullptr) {
        return false;
    } else {
        auto new_node = new CNode;
        new_node->data = e;
        new_node->next = prior_node->next;
        prior_node->next = new_node;
        return true;
    }
}

bool ListDelete(CLinklist &L, int i, ElemType &e) {
    CNode *prior_node = GetElem(L, i - 1);
    if (prior_node == nullptr) {
        return false;
    } else {
        CNode *del_node = prior_node->next;
        if (del_node == L) {
            return false;
        } else {
            e = del_node->data;
            prior_node->next = del_node->next;
            delete del_node;
            return true;
        }
    }
}

void PrintList(CLinklist L) {
    for (CNode *temp = L->next; temp != L; temp = temp->next) {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}

bool Empty(CLinklist L) {
    return L->next == L;
}

void DestroyLiList(CLinklist &l) {
    if (l->next != l) {
        DestroyLiList(l->next);
    }
    delete l;
    l = nullptr;
}




