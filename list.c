#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int number;
    struct node* next;
}LNode;
LNode* newnode() {//新增链表
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if (p == NULL) {
        printf("ERROR");
        exit(-1);
    }
    return p;
}
void insert(LNode** l, int num) {//插入
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if (p == NULL) {
        printf("ERROR");
        exit(-1);
    }
    p->number = num;
    p->next = NULL;
    if (*l == NULL || num < (*l)->number) {
        p->next = *l;
        *l = p;
        return;
    }
    LNode* cur = *l;
    while (cur->next != NULL && cur->next->number < num) {
        cur = cur->next;
    }
    p->next = cur->next;
    cur->next = p;
}
void insert_1(LNode** l, int num) {//插入
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if (p == NULL) {
        printf("ERROR");
        exit(-1);
    }
    p->number = num;
    p->next = NULL;
    if (*l == NULL || num > (*l)->number) {
        p->next = *l;
        *l = p;
        return;
    }
    LNode* cur = *l;
    while (cur->next != NULL && cur->next->number > num) {
        cur = cur->next;
    }
    p->next = cur->next;
    cur->next = p;
}
void destroy(LNode* l) {//销毁
    LNode* l1;
    while (l != NULL) {
        l1 = l;
        l = l->next;
        free(l1);
    }
}
void print(LNode* l) {//输出
    if (l == NULL) {
        printf("\n");
        return;
    }
    printf("%d", l->number);
    l = l->next;
    while (l != NULL) {
        printf("->%d", l->number);
        l = l->next;
    }
    printf("\n");
}
int main() {
    int num;
    LNode* la = newnode();
    la = NULL;
    LNode* lb = newnode();
    lb = NULL;
    LNode* lc = newnode();
    lc = NULL;
    LNode* ld = newnode();
    ld = NULL;
    while (scanf("%d", &num) != EOF) {
        if (num > 0) {
            insert(&la, num);
            insert_1(&lc, num);
        }
        if (num < 0) {
            insert(&lb, num);
            insert_1(&ld, num);
        }
    }
    print(la);
    print(lb);
    print(lc);
    print(ld);
    destroy(la);
    destroy(lb);
    destroy(lc);
    destroy(ld);
    return 0;
}