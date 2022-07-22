//
// Created by jin on 22-7-21.
//

#ifndef UNTITLED1_CDLINKLIST_H
#define UNTITLED1_CDLINKLIST_H

typedef int ElemType;

typedef struct CDNode {
    ElemType data;
    struct CDNode *prior, *next;
} CDNode, *CDLinklist;
void InitList(CDLinklist &L);
int Length(CDLinklist L);
CDNode *LocateElem(CDLinklist L, ElemType e);
CDNode *GetElem(CDLinklist L, int i);
bool ListInsert(CDLinklist &L, int i, ElemType e);
bool ListDelete(CDLinklist &L, int i, ElemType &e);
void PrintList(CDLinklist L);
bool Empty(CDLinklist L);

#endif //UNTITLED1_CDLINKLIST_H
