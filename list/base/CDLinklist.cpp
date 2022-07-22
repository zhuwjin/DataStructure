#include <iostream>
#include "CDLinklist.h"


void InitList(CDLinklist &L) {
    L = new CDNode;
    L->next = L;
    L->prior = L;
}

int Length(CDLinklist &L) {
    int length = 0;
    for (CDNode *temp = L->next; temp != L; temp = temp->next) {
        length += 1;
    }
    return length;
}

CDNode *LocateElem(CDLinklist L, ElemType e) {
    CDNode *temp = L->next;
    while (temp != L && temp->data != e) {
        temp = temp->next;
    }
    return temp == L ? nullptr : temp;
}

CDNode *GetElem(CDLinklist L, int i) {
    if (i < 0) {
        return nullptr;
    }
    if (i == 0) {
        return L;
    }
    CDNode *temp = L->next;
    while (temp != L && i > 1) {
        temp = temp->next;
        i -= 1;
    }
    return temp == L ? nullptr : temp;
}

bool ListInsert(CDLinklist &L, int i, ElemType e) {
    CDNode *prior_node = GetElem(L, i - 1);
    if (prior_node == nullptr) {
        return false;
    } else {
        CDNode *new_node = new CDNode;
        new_node->data = e;
        new_node->prior = prior_node;
        new_node->next = prior_node->next;
        prior_node->next = new_node;
        new_node->next->prior = new_node;
        return true;
    }
}

bool ListDelete(CDLinklist &L, int i, ElemType &e) {
    CDNode *prior_node = GetElem(L, i - 1);
    if (prior_node == nullptr) {
        return false;
    } else {
        CDNode *del_node = prior_node->next;
        if (del_node == L) {
            return false;
        } else {
            e = del_node->data;
            prior_node->next = del_node->next;
            del_node->next->prior = prior_node;
            return true;
        }
    }
}


void PrintList(CDLinklist L) {
    for (CDNode *temp = L->next; temp != L; temp = temp->next) {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}

bool Empty(CDLinklist L) {
    return L->next == L;
}


