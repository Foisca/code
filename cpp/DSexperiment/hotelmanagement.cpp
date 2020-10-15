//
// Created by Foisca on 10/7/2020.
//
#include "head.h"

//定义客房链表节点
typedef struct HNode {
    char roomN[10];         //客房名称
    float Price;            //标准价格
    float PriceL;           //入住价格(默认值=标准价格*0.8)
    int Beds;               //床位数Beds
    char Status[10];        //入住状态(值域:空闲.入住.预定。默认空闲)
    struct HNode *next;     //指针域
} Hotel, *HLink;

/*
(1)实现创建客房信息链表函数void Build(HLink &H).输入(客房名称、标准价格、床位数),
同时修改入住价格、入住状态为默认值.即入住价格=标准价格*80%.入住状态为"空闲"
提示:用strcpy()字符串拷贝函数。为了提高程序调试效率,
要求:用文件操作来输入客房信息(客房名称、标准价格、床位数);"E:\\data.txt"
 */
void Build(HLink &head, char *filepath) {
    FILE *fp;
    if (NULL == (fp = fopen(filepath, "r"))) {
        printf("error");
        exit(0);
    }
    HLink r, p;
    head = new HNode;
    r = head;
    while (!feof(fp)) {
        p = new HNode;
        fscanf(fp, "%s %f,%d\n", p->roomN, &p->Price, &p->Beds);
//        printf("%s %f %d\n", p->roomN, p->Price, p->Beds);
        p->PriceL = 0.8 * p->Price;
        strcpy(p->Status, "free");
//        printf("do\n");
        p->next = r->next;
        r->next = p;
        r = p;
        r->next = NULL;
    }
}

/*
(2)实现输出客房信息函数void Exp(HLink H).输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态;
 */
void Exp(HLink &head) {
    HLink p;
    p = head->next;
    printf("roomN\tPrice\tPriceL\tBeds\tStatus\n");
    while (p) {
        printf("%4s   %6.1f  %6.1f%5d  %8s\n", p->roomN, p->Price, p->PriceL, p->Beds, p->Status);
        p = p->next;
    }
    printf("\n");
}

/*
(3)函数int Find(HLink &H, char *roomN).查找房间名称为roomN的客房。如果找到.则返回该客房在链表中的位置序号(>=1).否则返回0。
提示:用strcmp()字符串比较函数
 */
int Find(HLink &head, char *name) {
    HLink p = head->next;
    int count = 1;
    while (p) {
        if (strcmp(name, p->roomN) == 0) return count;
        else {
            p = p->next;
            count++;
        }
    }
    return 0;
}

/*
(4)实现函数void updateH(HLink &H, int beds, char *state).将床位数为beds的客房入住状态改为state。提示:用strcpy()字符串拷贝函数;
 */
void updateH(HLink &head, int beds, char *state) {
    HLink p = head->next;
    for (int i = 1; i < beds; i++) {
        if (!p) {
            exit(0);
            printf("out of range!");
        }
        p = p->next;
    }
    strcpy(p->Status, state);
}

/*
(5)函数void Add(HLink &H).将该链表中未入住的客房入住价格均加价20%;
 */
void Add(HLink &head) {
    HLink p = head->next;
    while (p) {
        if (strcmp(p->Status, "free") == 0)
            p->PriceL *= 1.2;
        p = p->next;
    }
}

/*
(6)求出入住价格最高的客房函数HLink FirstH(HLink &H).该函数内return语句返回入住价格最高的客房结点指针.返回前将该结点在链表中删除;
 */
HLink FirstH(HLink &head) {
    HLink Top, p;
    p = head->next;
    Top = new HNode;
    Top->PriceL = 0;
    while (p) {
        if (p->PriceL > Top->PriceL)
            Top = p;
        p = p->next;
    }
    return Top;
}

/*
(7)函数void MoveK1(HLink &H, int k).将单链表中倒数第k个结点之后的所有结点移到头结点后面.注意:严禁采用先计算链表长度n再减k(即n-k)的方法;
*/
void MoveK1(HLink &head, int k) {
    HLink bfast = head, bslow = head;
    for (int i = 0; i < k; i++)
        bfast = bfast->next;
    while (bfast->next) {
        bfast = bfast->next;
        bslow = bslow->next;
    }
    bfast->next = head->next;
    head->next = bslow->next;
    bslow->next = NULL;
}

/*
(8)函数void ReverseN2(HLink &H).将单链表的正中间位置结点之后的全部结点倒置的功能.
 注意:严禁采用先计算链表长度n再除以2(即n/2)的方法;
*/
void ReverseN2(HLink &head) {
    HLink fast = head, mid = head;
    while (fast) {
        fast = fast->next->next;
        mid = mid->next;
    }
    HLink rear = mid->next;
    HLink p = rear->next;
    while (p) {
        rear->next = p->next;
        p->next = mid->next;
        mid->next = p;
        p = rear->next;
    }
}

/*
(9)函数void SortPriceL(HLink &H).按照客房(入住价格.客房名称)升序排序;
 */
//递增排序
//冒泡排序
void InSortPriceL(HLink &head) {
    HLink rear = head;
    HLink pp, p, q;
    while (rear->next) rear = rear->next;
    while (rear != head->next) {
        pp = head;
        p = pp->next;
        q = p->next;
//        printf("do\n");
        while (pp->next->next != rear) {
            if (p->PriceL > q->PriceL) {
//                printf("%d <-> %d\n", p->Beds, q->Beds);
                p->next = q->next;
                q->next = pp->next;
                pp->next = q;
            }
            pp = pp->next;
            p = pp->next;
            q = p->next;
        }
        if (p->PriceL > q->PriceL) {
//            printf("%d <-> %d\n", p->Beds, q->Beds);
            p->next = q->next;
            q->next = pp->next;
            pp->next = q;
        } else {
            rear = pp->next;
        }
    }
}

//递减排序
//冒泡排序
void DeSortPriceL(HLink &head) {
    HLink rear = head;
    HLink pp, p, q;
    while (rear->next) rear = rear->next;
    while (rear != head->next) {
        pp = head;
        p = pp->next;
        q = p->next;
        while (pp->next->next != rear) {
            if (p->PriceL < q->PriceL) {
                p->next = q->next;
                q->next = pp->next;
                pp->next = q;
            }
            pp = pp->next;
            p = pp->next;
            q = p->next;
        }
        if (p->PriceL < q->PriceL) {
            p->next = q->next;
            q->next = pp->next;
            pp->next = q;
        } else {
            rear = pp->next;
        }
    }
}

/*
(10)函数void upBed(HLink &H,int beds).创建一个[床位数为beds的新结点]
(还需输入:客房名称、标准价格等信息).使链表的形态为:
[头结点]->[床位数>beds的结点]->[床位数为beds的新结点]->[床位数<=beds的结点].
 要求[超过beds的结点]和[不超过beds的结点]这两段链表中的结点保持原来的前后相对顺序;
 */
void upBed(HLink &head, int beds) {
    HLink fast, slow, now;
    slow = head;
    fast = slow->next;
    now = new HNode;
    printf("please enter the name and PriceL of the room:\n");
    scanf("%s %f", now->roomN, &now->Price);
    now->Beds = beds;
    now->PriceL = now->Price * 0.8;
    strcpy(now->Status, "free");
    now->next = NULL;
    while (fast->Beds < beds) {
        fast = fast->next;
        slow = slow->next;
    }
    now->next = fast;
    slow->next = now;
}

/*
(11)实现函数void Merge(HLink &H1, HLink &H2).
 将两个按入住价格非递减排序的客房记录单合并为一个按入住价格非递增排序的客房记录单;
 要求算法的时间复杂度不超过两个链表的长度之和O(m+n);
 */
void Merge(HLink &head1, HLink head2) {
    HLink p1, p2, pp1, small;
    small = head2;
    bool p1first = true;
    if (head1->next->Beds >= head2->next->Beds) {
        HLink temp;
        while (head1->next->Beds >= small->next->Beds) small = small->next;
        temp = head2->next;
        head2->next = small->next;
        small->next = head1->next;
        head1->next = temp;
    }
    pp1 = head1, p1 = pp1->next;
    p2 = head2->next;
    while (p1 && p2) {
        if (p1->Beds > p2->Beds) {
            pp1->next = p1->next;
            p1->next = head1->next;
            head1->next = p1;
            if (p1first) {
                pp1 = pp1->next;
                p1first = false;
            }
            p1 = pp1->next;
        } else {
            head2->next = p2->next;
            p2->next = head1->next;
            head1->next = p2;
            p2 = head2->next;
        }
    }
    if (!p1) {
        while (p2) {
            head2->next = p2->next;
            p2->next = head1->next;
            head1->next = p2;
            p2 = head2->next;
        }
    } else {
        while (p1) {
            pp1->next = p1->next;
            p1->next = head1->next;
            head1->next = p1;
            pp1 = pp1->next;
            p1 = pp1->next;
        }
    }
}

/*
(12)主函数main()调用以上函数.(3)若返回值>=1则输出该客房在链表中的位置序号.否则输出该客房不存在;
 输出(4)~(10)处理后的链表内容.其中(6)还要输出入住价格最高的客房信息。
 */
HLink reverse(HLink &head) {
    if (head == NULL || head->next == NULL)return head;
    HLink re = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return re;
}

int main() {
    HLink head, test;
    Build(head, "E:\\data.txt");
    Build(test, "E:\\data1.txt");
//    Exp(head);
    Exp(test);
//    updateH(head, 2, "checked");
//    Exp(head);
//    printf("\n");
//    Add(head);
//    Exp(head);
//    printf("%d", FirstH(head)->Beds);
//    MoveK1(head, 2);
//    ReverseN2(head);
    InSortPriceL(head);
    Exp(head);
    Merge(head, test);
//    upBed(head, 5);
    Exp(head);
}

