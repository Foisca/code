// ʵ��һ�����һ������ʵ�����Ա��ϲ�������
// e1list.cpp : �������̨Ӧ�ó������ڵ㡣
// 

#include "p1list.h"

/* �˺������ڳ�ʼ��һ��������������Ա�L
 * L�ĳ�ֵ��ͨ�����̰��յ����Ĵ���һ����Ȼ��һ����Ȼ������ġ�
 */
void InitList(List &L) {
    int i = 0, d;
    L.elem[0] = GUARD;
    printf("����ĳ���Ա����Ԫ�ص�ֵ(��Ȼ��)��%d��ʾ���������\n", GUARD);
    do {
        scanf("%d", &d);
        if (d != GUARD) {
            if (i != 0 && d < L.elem[i - 1])
                printf("\n����Ҫ��ʼ��һ��������������Ա�������һ����С�ڵ�%d��Ȼ��", L.elem[i]);
            else L.elem[i++] = d;
        }
        if (i == MAXLEN) printf("\n�����Ա��ȴﵽ���ֵ\n");
    } while ((d != GUARD) && (i < MAXLEN));
    L.length = i;
}

/* �˺������ڳ�ʼ��һ�����Ա�L
 * L�ĳ�ֵ��ͨ������һ����Ȼ��һ����Ȼ������ġ�
 */
void InitList0(List &L) {
    int i = 0, d;
    L.elem[0] = GUARD;
    printf("����ĳ���Ա����Ԫ�ص�ֵ(��Ȼ��)��%d��ʾ���������\n", GUARD);
    do {
        scanf("%d", &d);
        if (d != GUARD) L.elem[i++] = d;
        if (i == MAXLEN) printf("\n�����Ա��ȴﵽ���ֵ\n");
    } while ((d != GUARD) && (i < MAXLEN));
    L.length = i;
}

void printList(List L) {
    int i;
    printf("���Ա�[%d]:\t", L.length);
    for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
    printf("\n");
}

void createTwoLists(List &La, List &Lb) {
    printf("\n�����������Ա�--ע�������������ܳ��Ȳ�Ҫ����%d\n", MAXLEN);
    InitList(La);
    printf("\n��ʼ�����Ա�Lb���䳤�Ȳ�����%d���������ֱ��ضϣ�\n", MAXLEN - La.length);
    InitList(Lb);
    if (La.length + Lb.length > MAXLEN) Lb.length = MAXLEN - La.length;
}


/*TBD1* ��Lb�鲢��La���γ��±�Lc
 *TBD1* Ҫ��Lc����������������ظ�Ԫ��
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

/*TBD2* ����La��Lb�ֱ��ʾ�������ϣ����¼���La��La U Lb�� U"��"������
 *TBD2* ע�⼯���ﲻ��������ظ�Ԫ��
 *TBD2*/
void insertElem(List &L, int e, int position) {
    //position Ϊ�ڼ���,��1��ʼ
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


/*TBD3* �����Ա�L��ת
 *TBD3* Ҫ��ʹ�����ٵĸ��ӿռ䣬�ռ临�Ӷ�ΪO(1)��
 *TBD3*/
void ReverseList(List &L) {
    int temp;
    for (int i = 0; i < (L.length / 2); i++) {
        temp = L.elem[i];
        L.elem[i] = L.elem[L.length - i - 1];
        L.elem[L.length - i] = temp;
    }
}

/*TBD4* ��һ������˳���L��ɾ��Ԫ��ֵ��x��y֮�������Ԫ��(x <= y)
 *TBD4* Ҫ���Խϸߵ�Ч��ʵ�֣��ռ临�Ӷ�ΪO(1)��
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


//    printf("\n���������ַ������˳� ......");
//    getchar();
//    return 0;
}
//           1 2 3 4 -99

//             1 2 3 4 5 6 7 8 9 -99
