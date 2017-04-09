#include <iostream>
#include <stdlib.h>
#define LIST_INIT_SIZE     100
#define LIST_INCREMENT    10
using namespace std;
   typedef int ElemType;
   typedef struct {
     ElemType     *elem;
    int         length;
    int         listsize;
}SqList;

   void InitList(SqList *L)
   {

     L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
      if (!L->elem)
         return ;
       L->length = 0;
       L->listsize = LIST_INIT_SIZE;
 }

  void DestroyList(SqList *L)
  {
     free(L->elem);
     L->length = 0;
     L->listsize = 0;
  }

  void ClearList(SqList *L)
  {
      L->length = 0;
  }

  bool ListEmpty(SqList *L)
  {
     return (L->length == 0);
  }

  int ListLength(SqList *L)
  {
       return L->length;
}

  int GetElem(SqList *L, int i, ElemType *e)
   {
     if (i < 0 || i >= L->length)
         return -1;
    *e = L->elem[i];
     return 0;
   }



  int ListInsert(SqList *L, int i, ElemType e)
  {
     if (i < 0 || i > L->length) {
        return -1;
    }

     if (L->length >= L->listsize) {
        ElemType *newbase = (ElemType *)realloc(L->elem, sizeof(ElemType) * (L->listsize + LIST_INCREMENT));
         if (!newbase) {
            return -1;
          }
        L->elem = newbase;
        L->listsize += LIST_INCREMENT;
    }

    ElemType *p, *q;
    q = L->elem + i;
    for (p = L->elem + L->length - 1; p >= q; --p)
        *(p+1) = *p;
        *q = e;
        L->length += 1;

    return 0;
}

   int ListDelete(SqList *L, int i, ElemType *e)
{
    if (i < 0 || i >= L->length) {
         return -1;
     }
     *e = L->elem[i];
     ElemType *p;
    for (p = L->elem + i; p < L->elem + L->length - 1; ++p) {
        *p = *(p+1);
    }
    L->length -= 1;

    return 0;
}
  int LocateElem(SqList *L, ElemType e, bool (*compare)(ElemType a, ElemType b))
   {
      int i;

      for (i = 0; i < L->length; ++i) {
        if (compare(L->elem[i], e))
            return i;
    }

    return -1;
}

   int ListTraverse(SqList *L, int (*visit)(ElemType e))
{
    int i, ret;

    for (i = 0; i < L->length; ++i) {
       ret = visit(L->elem[i]);
         if (ret != 0)
           return ret;
    }

     return 0;
 }
int Display(SqList *L,int n){
    int i;
    for(i=0;i<n;i++)
    cout<<L->elem[i]<<" ";
   return 0;
 }

int main()
{
   SqList *L;
   InitList(L);
   int i,k;
   cout<<"Please input 10 numbers"<<endl;

   return 0;
   }
