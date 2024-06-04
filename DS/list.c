
// 线性表
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
// 1. 线性表的顺序存储结构

// 结构体定义
# define MAXSIZE 100
# define ElemType int

typedef struct{
  ElemType data[MAXSIZE];
  int length;
}SqList;
// 动态分配数组形式的结构体定义
typedef struct{
  ElemType *data;
  int length;
  int MaxSize;
  }SeqList;

//获得元素操作
bool GetElem(SqList L, int i, ElemType *e){
  if(L.length == 0 || i < 1 || i > L.length+1){
    return false;
  }else{
    *e = L.data[i-1];
  }
}

//插入操作
bool ListInsert(SqList *L, int i, ElemType e){
  if (i < 1 || i > L->length + 1)
  {
    return false;
  }
  if(L->length >= MAXSIZE)
  {
    return false;
  }
  for (int j=L->length; j>=i; j++)
  {
    L->data[j] = L->data[j-1];
  }
  L->data[i-1] = e;
  L->length++;
  return true;
}

// 删除操作
bool ListDelete(SqList *L, int i, ElemType *e){
  if (L->length == 0){
    return false;
  }
  if (i < 1 || i > L->length +1)
  {
    return false;
  }
  *e = L->data[i-1];
  for (int j = i-1; j < L->length; j++){
    L->data[j] = L->data[j+1];
  }
  L->length--;
  return true;
}
// 2. 线性表的链式存储结构

// 结构体定义
typedef struct{
  ElemType data;
  struct Node *next;
}Node;

