#include "p1list.h"


//创建一个带头结点的长度为n的单链表L
Status CreateList_L(LinkList &L, int n) {
	LinkList pf, p;
	int i;
	//[1]创建表L的头结点
	L=(LinkList)malloc(sizeof(LNode));
	L->data=n;
	L->next=NULL;
	pf=L;
	printf("顺序输入%d个自然数，即单链表的数据：\n", n);
	for (i=0;i<n;i++) {
		//[2]创建新结点p，与它的前驱结点pf链接
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next=pf->next;
		pf->next=p;
		pf=p;
	}
	return OK;
}

void printList_L(LinkList L) {
	LNode *p=L;
	printf("单链表的内容：\n");
	while(p) {
		printf("[%d]-->", p->data);
		p=p->next;
	}
	printf("\n");
}

Status GetElem_L(LinkList L, int i, ElemType &e){
	int j;
	LinkList p;
	if (i>L->data) return ERROR;
	p=L; j=1;
	while (p&&j<i) {
		p=p->next; 
		j++;
	}
	e=p->data;
	return OK;
}

//在带头结点的单链表L中第i个位置之前插入元素e
Status ListInsert_L(LinkList &L, int i, ElemType e) {
	LinkList c,p,n;
	int j=1;
	//[0]第i个位置不存在
	if (i<1||i>L->data) return ERROR;
	c=L->next;
	//[1]找到第i个结点c，其前驱为结点p
	while (c&&j<i) {p=c; c=c->next; j++;}
	//[2]在结点p和结点c之间插入新结点，其data值为e
	n=(LinkList)malloc(sizeof(LNode));
	n->data=e;
	p->next=n;
	n->next=c;
	L->data++;
	return OK;
}

//在带头结点的单链表L中，删除第i个元素，并由e返回其值
Status ListDelete_L(LinkList &L, int i, ElemType &e){
	//[1]找到第i个结点c, 其前驱为结点p
	//[2]删除结点c
	return OK;
}

//已知单链表La和Lb的元素按值非递减排列。归并La和Lb得到新的单链表Lc。要求Lc的元素按值非递减排列。
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc){
	LinkList pa, pb, pc;
	pa=La->next;
	pb=Lb->next;
	pc=Lc=La;
	while (pa) { 
		//[1]结点pa的值和结点pb的值比较
		if (pa->data <= pb->data) {
			//[1.1]pa->data <= pb->data时，使结点pa为结点pc的后继，pa指向原后继
			pc->next=pa; pc=pa; pa=pa->next; }
		else {//[1.2]否则，使结点pb为结点pc的后继，pb指向原后继
			pc->next=pb; pc=pb; pb=pb->next; }
	}

	//[2]结点pb有后继时，链在结点pc后
	if (pb) pc->next=pb;
}

//习题与解析2-3-20
//从一个递增有序的带头结点的单链表L中删除值<=max且>=min的结点
void deleteallnodes(LinkList &L, ElemType min, ElemType max) {
	LinkList c,p;
	p=c=L->next;
	while (c && (c->data <= max)) {
		if ((c->data <= max)&&(c->data >=min)) {
		//1.1当前结点c的值<=max且>=min时，删除c
			p->next=c->next;
			free(c);
			L->data--;
			c=p->next;
		} else {
		//1.2否则移动到当前结点c的后继
			p=c;
			c=c->next;
		}
	}
}