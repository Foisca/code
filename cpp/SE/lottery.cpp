#include "p1list.h"
#include<time.h>

/*TBD1* �Ҹ���-��ʼ��ѭ������L
 *TBD1* ����sizeΪ���С
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

/*TBD1* �׸���-����Ļ���������L������
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

/*TBD2* �Ҹ���-ʵ��������Ʊ��10ѡ7��
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

/*TBD2* �׸���-ʵ��������Ʊ��36ѡ7��
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

/*TBD3* �׸���-�ͷų�ʼ������L��ʹ�õ��ڴ�
 *TBD3*/
void freeList(LinkList &L) {
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        free(p);
    }
}

/*TBD3* �Ҹ���-ʵ��������
 *TBD3*/
int main() {
    LinkList test;
    test = new LNode;
    test->next = NULL;
//    select10(test);
    select36(test);
    display(test);

}
