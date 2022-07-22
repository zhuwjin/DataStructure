//
// Created by jin on 22-7-21.
//

#ifndef UNTITLED1_CLINKLIST_H
#define UNTITLED1_CLINKLIST_H

typedef int ElemType;

typedef struct CNode {
    ElemType data;
    struct CNode *next;
} CNode, *CLinklist;

void InitList(CLinklist &L);
int Length(CLinklist L);
CNode *LocateElem(CLinklist L, ElemType e);
CNode *GetElem(CLinklist L, int i);
bool ListInsert(CLinklist &L, int i, ElemType e);
bool ListDelete(CLinklist &L, int i, ElemType &e);
void PrintList(CLinklist L);
bool Empty(CLinklist L);
void DestroyLiList(CLinklist &l);

#endif //UNTITLED1_CLINKLIST_H
