//------Head files for list in chapter 2 --------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//预定义常量
#define TRUE        1
#define FALSE        0
#define OK            1
#define ERROR        0
#define INFEASIBLE    -1
#define OVERFLOW    -2
#define GUARD    -99
#define MAXLEN 255          //线性表(顺序表)的最大长度
#define LIST_MAX_SIZE    50  //链表的最大长度

//函数结果的类型
typedef int Status;

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

typedef struct List {
    int elem[MAXLEN];
    int length;
} List;

typedef unsigned char SString[MAXLEN + 1];

typedef int ElemType;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//---------- p1list.cpp ---------------------------------------------
void InitList(List &L); //* 此函数用于初始化一个保持增序的线性表L
void InitList0(List &L); //* 此函数用于初始化一个线性表L
void printList(List L);

void createTwoLists(List &La, List &Lb);

void MergeList(List La, List Lb, List &Lc); //*TBD1* 将Lb归并到La表，形成新表Lc
void Union(List &La, List Lb); //*TBD2* 线性La和Lb分别表示两个集合，求新集合La＝La U Lb（ U"并"操作）
void ReverseList(List &L); //*TBD3* 将线性表L逆转
void deleteall(List &L, int x, int y); //*TBD4* 从一给定的顺序表L中删除元素值在x和y之间的所有元素(x<= y)

//--------- lottery.cpp ----------------------------------------------
void build(LinkList &L, int size); //*TBD1* 乙负责-初始化循环链表L
void display(LinkList L); //*TBD1* 甲负责-在屏幕上输出链表L的内容
void select10(LinkList &L); //*TBD2* 乙负责-实现体育彩票（10选7）
void select36(LinkList &L); //*TBD2* 甲负责-实现体育彩票（36选7）
void freeList(LinkList &L); //*TBD3* 甲负责-释放初始化链表L所使用的内存
void mainlottery(); //*TBD3* 乙负责-实现主函数

//--------- LinkedList.cpp --------------------------------------------
Status CreateList_L(LinkList &L, int n); //采用尾插法创建一个带头结点的长度为n的单链表L
Status CreateList_L_NoHead(LinkList &L, int n); //采用尾插法创建一个无头结点的长度为n的单链表L
void printList_L(LinkList L); //输出带头结点的单链表L
void printList_L_NoHead(LinkList L); //输出不带头结点的单链表L
Status GetElem_L(LinkList L, int i, ElemType &e);

Status ListInsert_L(LinkList &L, int i, ElemType e);

Status ListDelete_L(LinkList &L, int i, ElemType &e);

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

void deleteallnodes(LinkList &L, ElemType min, ElemType max);

void ChangeLinkList01J(LinkList &L);

Status reorder5(LinkList &L);

//--------- p1list.cpp [例2-2-12] -----------------------------------
void deleteall_1(List *L, int x);

void deleteall_2(List *L, int x);

void deleteall_3(List *L, int x);