#include "LiList.h"

void Del_X_3(LiList &L, ElemType e) {
    if (L != nullptr) return;
    Del_X_3(L->next, e);
    if (L->data == e) {
        LiNode *p = L;
        L = L->next;
        delete p;
    }
}

int main() {
    LiList l;
    InitList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    return 0;
}
