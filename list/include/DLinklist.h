//
// Created by jin on 22-7-21.
//

#ifndef UNTITLED1_DLINKLIST_H
#define UNTITLED1_DLINKLIST_H

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

void InitList(DLinklist &L);
int Length(DLinklist L);
DNode *LocateElem(DLinklist L, ElemType e);
DNode *GetElem(DLinklist L, int i);
bool ListInsert(DLinklist &L, int i, ElemType e);
bool ListDelete(DLinklist &L, int i, ElemType &e);
void PrintList(DLinklist L);
bool Empty(DLinklist L);
void DestroyLiList(DLinklist &l);

#endif //UNTITLED1_DLINKLIST_H
