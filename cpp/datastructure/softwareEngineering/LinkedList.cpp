#include "p1list.h"


//����һ����ͷ���ĳ���Ϊn�ĵ�����L
Status CreateList_L(LinkList &L, int n) {
	LinkList pf, p;
	int i;
	//[1]������L��ͷ���
	L=(LinkList)malloc(sizeof(LNode));
	L->data=n;
	L->next=NULL;
	pf=L;
	printf("˳������%d����Ȼ����������������ݣ�\n", n);
	for (i=0;i<n;i++) {
		//[2]�����½��p��������ǰ�����pf����
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
	printf("����������ݣ�\n");
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

//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ����Ԫ��e
Status ListInsert_L(LinkList &L, int i, ElemType e) {
	LinkList c,p,n;
	int j=1;
	//[0]��i��λ�ò�����
	if (i<1||i>L->data) return ERROR;
	c=L->next;
	//[1]�ҵ���i�����c����ǰ��Ϊ���p
	while (c&&j<i) {p=c; c=c->next; j++;}
	//[2]�ڽ��p�ͽ��c֮������½�㣬��dataֵΪe
	n=(LinkList)malloc(sizeof(LNode));
	n->data=e;
	p->next=n;
	n->next=c;
	L->data++;
	return OK;
}

//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_L(LinkList &L, int i, ElemType &e){
	//[1]�ҵ���i�����c, ��ǰ��Ϊ���p
	//[2]ɾ�����c
	return OK;
}

//��֪������La��Lb��Ԫ�ذ�ֵ�ǵݼ����С��鲢La��Lb�õ��µĵ�����Lc��Ҫ��Lc��Ԫ�ذ�ֵ�ǵݼ����С�
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc){
	LinkList pa, pb, pc;
	pa=La->next;
	pb=Lb->next;
	pc=Lc=La;
	while (pa) { 
		//[1]���pa��ֵ�ͽ��pb��ֵ�Ƚ�
		if (pa->data <= pb->data) {
			//[1.1]pa->data <= pb->dataʱ��ʹ���paΪ���pc�ĺ�̣�paָ��ԭ���
			pc->next=pa; pc=pa; pa=pa->next; }
		else {//[1.2]����ʹ���pbΪ���pc�ĺ�̣�pbָ��ԭ���
			pc->next=pb; pc=pb; pb=pb->next; }
	}

	//[2]���pb�к��ʱ�����ڽ��pc��
	if (pb) pc->next=pb;
}

//ϰ�������2-3-20
//��һ����������Ĵ�ͷ���ĵ�����L��ɾ��ֵ<=max��>=min�Ľ��
void deleteallnodes(LinkList &L, ElemType min, ElemType max) {
	LinkList c,p;
	p=c=L->next;
	while (c && (c->data <= max)) {
		if ((c->data <= max)&&(c->data >=min)) {
		//1.1��ǰ���c��ֵ<=max��>=minʱ��ɾ��c
			p->next=c->next;
			free(c);
			L->data--;
			c=p->next;
		} else {
		//1.2�����ƶ�����ǰ���c�ĺ��
			p=c;
			c=c->next;
		}
	}
}