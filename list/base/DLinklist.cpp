#include <iostream>
#include "DLinklist.h"

void InitList(DLinklist &L) {
    L = new DNode;
    L->prior = nullptr;
    L->next = nullptr;
}

int Length(DLinklist L) {
    int length = 0;
    for (DNode *temp = L->next; temp != nullptr; temp = temp->next) {
        length += 1;
    }
    return length;
}

DNode *LocateElem(DLinklist L, ElemType e) {
    DNode *temp = L->next;
    while (temp != nullptr && temp->data != e) {
        temp = temp->next;
    }
    return temp;
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
        new_node->prior = prior_node;
        new_node->next = prior_node->next;
        prior_node->next = new_node;
        if (new_node->next != nullptr) {
            new_node->next->prior = new_node;
        }
        return true;
    }
}

bool ListDelete(DLinklist &L, int i, ElemType &e) {
    DNode *prior_node = GetElem(L, i - 1);
    if (prior_node == nullptr) {
        return false;
    } else {
        DNode *del_node = prior_node->next;
        if (del_node == nullptr) {
            return false;
        }
        e = del_node->data;
        prior_node->next = del_node->next;
        if (del_node->next != nullptr) {
            del_node->next->prior = prior_node;
        }
        delete del_node;
        return true;
    }
}

void PrintList(DLinklist L) {
    for (DNode *temp = L->next; temp != nullptr; temp = temp->next) {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}

bool Empty(DLinklist L) {
    return L->next == nullptr;
}

void DestroyLiList(DLinklist &l) {
    if (l->next != nullptr) {
        DestroyLiList(l->next);
    }
    delete l;
    l = nullptr;
}