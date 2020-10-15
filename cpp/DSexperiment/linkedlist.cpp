//
// Created by Yjy09 on 10/7/2020.
//

#include "head.h"

typedef struct node {
    int val;
    struct node *next;

} Linkedlist, *Lnode;

void initList(Lnode &head, int n) {
    int e;
    Lnode p, r;
    head = new node;
    r = head;
    for (int i = 0; i < n; i++) {
        p = new node;
        scanf("%d", &e);
//        fscanf(data,"%d")
        p->val = e;
        p->next = r->next;
        r->next = p;
        r = p;
        r->next = NULL;
    }
}

// void initListByFile(Lnode &head, FILE *file) {
//     Lnode p, r;
//     head = new node;
//     char *str;
//     r = head;
//     while (!feof(file)) {
//         p = new node;
//         fgets(str, 1024, file);
//         p->val = atoi(str);
//         p->next = r->next;
//         r->next = p;
//         r = p;
//         r->next = NULL;
//     }
// }

void show(Lnode head) {
    Lnode p = head->next;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void insertNode(Lnode &head, int posistion, int e) {
    Lnode p = head, q;
    q = new node;
    q->val = e;

    for (int i = 1; i < posistion; i++) {
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}

void deleteNode(Lnode &head, int position) {
    Lnode q = head, p;
    for (int i = 1; i < position; ++i) {
        q = q->next;
    }
    p = q->next;
    q->next = p->next;
    free(p);
}
//
//int main() {
//    Lnode mylist;
//    initList(mylist,5);
//    show(mylist);
//}