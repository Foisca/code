// 实验一：设计一个程序实现线性表上并操作。
// e1list.cpp : 定义控制台应用程序的入口点。
// 

#include "p1list.h"

/* 此函数用于初始化一个保持增序的线性表L
 * L的初值是通过键盘按照递增的次序一个自然数一个自然数输入的。
 */
void InitList(List &L) {
    int i = 0, d;
    L.elem[0] = GUARD;
    printf("输入某线性表各个元素的值(自然数)，%d表示输入结束！\n", GUARD);
    do {
        scanf("%d", &d);
        if (d != GUARD) {
            if (i != 0 && d < L.elem[i - 1])
                printf("\n这里要初始化一个保持增序的线性表，请输入一个不小于的%d自然数", L.elem[i]);
            else L.elem[i++] = d;
        }
        if (i == MAXLEN) printf("\n该线性表长度达到最大值\n");
    } while ((d != GUARD) && (i < MAXLEN));
    L.length = i;
}

/* 此函数用于初始化一个线性表L
 * L的初值是通过键盘一个自然数一个自然数输入的。
 */
void InitList0(List &L) {
    int i = 0, d;
    L.elem[0] = GUARD;
    printf("输入某线性表各个元素的值(自然数)，%d表示输入结束！\n", GUARD);
    do {
        scanf("%d", &d);
        if (d != GUARD) L.elem[i++] = d;
        if (i == MAXLEN) printf("\n该线性表长度达到最大值\n");
    } while ((d != GUARD) && (i < MAXLEN));
    L.length = i;
}

void printList(List L) {
    int i;
    printf("线性表[%d]:\t", L.length);
    for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
    printf("\n");
}

void createTwoLists(List &La, List &Lb) {
    printf("\n创建两个线性表--注意输入的两表的总长度不要超过%d\n", MAXLEN);
    InitList(La);
    printf("\n初始化线性表Lb，其长度不超过%d。超出部分被截断！\n", MAXLEN - La.length);
    InitList(Lb);
    if (La.length + Lb.length > MAXLEN) Lb.length = MAXLEN - La.length;
}


/*TBD1* 将Lb归并到La表，形成新表Lc
 *TBD1* 要求Lc保持有序，允许出现重复元素
 *TBD1*/
void MergeList(List La, List Lb, List &Lc) {
    Lc.length = La.length + Lb.length;
    int x = 0, y = 0, i = 0;
    while ((x < La.length) && (y < Lb.length)) {
        if (La.elem[x] < Lb.elem[y]) {
            Lc.elem[i] = La.elem[x];
            x++, i++;
        } else {
            Lc.elem[i] = Lb.elem[y];
            y++, i++;
        }
    }
    if (x < La.length)
        for (; x < La.length; i++, x++)
            Lc.elem[i] = La.elem[x];
    else
        for (; y < Lb.length; i++, y++)
            Lc.elem[i] = Lb.elem[y];

}

/*TBD2* 线性La和Lb分别表示两个集合，求新集合La＝La U Lb（ U"并"操作）
 *TBD2* 注意集合里不允许出现重复元素
 *TBD2*/
void insertElem(List &L, int e, int position) {
    //position 为第几个,从1开始
    L.length++;
    for (int i = L.length - 2; i > position - 1; i--) {
//        printf("do2");
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[position] = e;
}

void Union(List &La, List Lb) {
    int x = 0, y = 0, i = 0;
    while (x < La.length && y < Lb.length) {
        if (La.elem[x] > Lb.elem[y]) {
            insertElem(La, Lb.elem[y], i);
            y++;
        } else if (La.elem[x] == Lb.elem[y])y++;
//        printf("do\n");
        x++, i++;
    }
    if (x == La.length) {
        //La finished
        while (y != Lb.length) {
            insertElem(La, Lb.elem[y], i);
            y++, i++;
        }
    }
}


/*TBD3* 将线性表L逆转
 *TBD3* 要求使用最少的附加空间，空间复杂度为O(1)。
 *TBD3*/
void ReverseList(List &L) {
    int temp;
    for (int i = 0; i < (L.length / 2); i++) {
        temp = L.elem[i];
        L.elem[i] = L.elem[L.length - i - 1];
        L.elem[L.length - i] = temp;
    }
}

/*TBD4* 从一给定的顺序表L中删除元素值在x和y之间的所有元素(x <= y)
 *TBD4* 要求以较高的效率实现，空间复杂度为O(1)。
 *TBD4*/
void deleteall(List &L, int x, int y) {
    //      ( x , y ]
    for (; y < L.length; y++, x++) {
        L.elem[x] = L.elem[y];
    }
    L.length -= (y - x);
}


int sqlistmain(int argc, char *argv[]) {

    List a, b, c, d;
//    InitList(a);
//    InitList(b);
    a = {1, 2, 3, 4, 5, 6, 7, 8};
    a.length = 8;
    b = {5, 6, 7, 8, 9, 10};
    b.length = 6;
    d = {-1, 3, 4, 5, 90};
    d.length = 5;
//    MergeList(a, b, c);
    printf("a:");
    printList(a);
    printf("b:");
    printList(b);
    printf("d:");
    printList(d);
//    printList(c);
//    ReverseList(c);
//    printList(c);
    Union(a, b);
//    Union(b, a);
    printList(a);
    deleteall(a, 2, 5);
    printList(a);


//    printf("\n键入任意字符程序退出 ......");
//    getchar();
//    return 0;
}
//           1 2 3 4 -99

//             1 2 3 4 5 6 7 8 9 -99
