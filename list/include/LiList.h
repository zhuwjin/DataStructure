#ifndef UNTITLED1_LILIST_H
#define UNTITLED1_LILIST_H


typedef int ElemType;
typedef struct LiNode {
    ElemType data;
    struct LiNode *next;
} LiNode, *LiList;

void InitList(LiList &L);
int Length(LiList L);
LiNode *LocateElem(LiList L, ElemType e);
LiNode *GetElem(LiList L, int i);
bool ListInsert(LiList &L, int i, ElemType e);
bool ListDelete(LiList &L, int i, ElemType &e);
void PrintList(LiList L);
bool Empty(LiList L);
void DestroyLiList(LiList &l);

#endif //UNTITLED1_LILIST_H
