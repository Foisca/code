#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int elemType;

typedef struct sqQueue {
    int front;
    int rear;
    elemType *base;
};

Status initQueue(sqQueue &q) {
    q.rear = 1;
    q.front = 0;
    q = *new sqQueue[MAXQSIZE];
    return OK;
}

int sqLength(sqQueue q) {
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

Status appendElem(sqQueue &q, elemType e) {
    if (((q.rear + 1) % MAXQSIZE == q.front)) return ERROR;
    q.base[q.rear] = e;
    q.rear++;
}

int main() {
    sqQueue q;
    initQueue(q);
    appendElem(q, 1);
    printf("%d", sqLength(q));

}
