#include <iostream>
#include "LiList.h"

void InitList(LiList &L) {
    L = new LiNode;
    L->next = nullptr;
}

int Length(LiList L) {
    int length = 0;
    for (LiNode *temp = L->next; temp != nullptr; temp = temp->next) {
        length += 1;
    }
    return length;
}

LiNode *LocateElem(LiList L, ElemType e) {
    LiNode *temp = L->next;
    for (; temp != nullptr; temp = temp->next) {
        if (temp->data == e) {
            break;
        }
    }
    return temp;
}

LiNode *GetElem(LiList L, int i) {
    if (i < 0) {
        return nullptr;
    }
    LiNode *temp = L;
    for (int j = 0; j < i && temp != nullptr; j++) {
        temp = temp->next;
    }
    return temp;
}

bool ListInsert(LiList &L, int i, ElemType e) {
    LiNode *pNode = GetElem(L, i - 1);
    if (pNode == nullptr) {
        return false;
    } else {
        LiNode *newNode = new LiNode;
        newNode->data = e;
        newNode->next = pNode->next;
        pNode->next = newNode;
        return true;
    }
}

bool ListDelete(LiList &L, int i, ElemType &e) {
    LiNode *pNode = GetElem(L, i - 1);
    if (pNode == nullptr) {
        return false;
    } else {
        LiNode *delNode = pNode->next;
        if (delNode == nullptr) {
            return false;
        }
        e = delNode->data;
        pNode->next = delNode->next;
        delete delNode;
        return true;
    }
}

void PrintList(LiList L) {
    for (LiNode *temp = L->next; temp != nullptr; temp = temp->next) {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}

bool Empty(LiList L) {
    return L->next == nullptr;
}

void DestroyLiList(LiList &l) {
    if (l->next != nullptr) {
        DestroyLiList(l->next);
    }
    delete l;
    l = nullptr;
}