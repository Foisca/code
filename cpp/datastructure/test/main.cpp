#include<stdio.h>
#include<stdlib.h>

typedef struct HNode {
    int val;
    struct HNode *next;     //指针域
} Hotel, *NLink;

void Build(NLink &head,int n) {
    NLink r, p;
    int e;
    head = new HNode;
    r = head;
    for (int i = 0; i < n; i++) {
        printf("plese enter %d numbers:",n);
        scanf("%d",&e);
        p=new HNode;
        p->val=e;
        p->next = r->next;
        r->next = p;
        r = p;
        r->next = NULL;
    }
    
}
void swapOneTwo(NLink &head){
    NLink one,two,temp;
    one=head->next;
    two=one->next;
    temp=one;

    one=two;
    one->next=two->next;

    two=temp;
}


void show(NLink head){
    NLink p=head->next;
    printf("\n print:\n");
    while (p){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

int main(){
    NLink head;
    Build(head,4);
    show(head);
    swapOneTwo(head);
    show(head);
}