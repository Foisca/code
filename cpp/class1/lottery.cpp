#include "p1list.h"
#include<time.h>

/*TBD1* 乙负责-初始化循环链表L
 *TBD1* 其中size为其大小
 *TBD1*/
void build(LinkList &L, int size) {
    LinkList p, r;
    int e;
    r = L;
    printf("Please enter %d numbers:", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &e);
        p = new LNode;
        p->data = e;
        p->next = NULL;
        p->next = r->next;
        r->next = p;
        r = p;
    }
}

//LinkList newNode(int elem) {
//    return LinkList{elem, NULL}
//}

/*TBD1* 甲负责-在屏幕上输出链表L的内容
 *TBD1*/
void display(LinkList L) {
    if (!L) { printf("EmptyList\n"), exit(0); }

    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*TBD2* 乙负责-实现体育彩票（10选7）
 *TBD2*/
void appendElem(LinkList &L, int elem) {
    LinkList p = L;
    while (p->next) {
        p = p->next;
    }
    p->next = new LNode;
    p->next->data = elem;
    p->next->next = NULL;
}

bool inList(LinkList L, int elem) {
    LinkList p = L->next;
    while (p) {
        if (p->data == elem)return true;
        p = p->next;
    }
    return false;
}

void select10(LinkList &L) {
    int a, num = 0;
    srand((unsigned int) time(0));
    while (num < 7) {
        a = rand() % 10 + 1;
        if (!inList(L, a)) {
            num++;
            appendElem(L, a);
        }
    }
}

/*TBD2* 甲负责-实现体育彩票（36选7）
 *TBD2*/
void select36(LinkList &L) {
    int a, num = 0;
    srand((unsigned int) time(0));
    while (num < 7) {
        a = rand() % 36 + 1;
        if (!inList(L, a)) {
            num++;
            appendElem(L, a);
        }
    }

}

/*TBD3* 甲负责-释放初始化链表L所使用的内存
 *TBD3*/
void freeList(LinkList &L) {
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        free(p);
    }
}

/*TBD3* 乙负责-实现主函数
 *TBD3*/
int main() {
    LinkList test;
    test = new LNode;
    test->next = NULL;
//    select10(test);
    select36(test);
    display(test);

}
