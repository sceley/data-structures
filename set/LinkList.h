#include <iostream>
using namespace std;

typedef struct LinkNode {
    char data;
    struct LinkNode *next;
} LinkNode, *LinkNodePtr;

typedef struct LinkList {
    LinkNodePtr head;
    LinkNodePtr tail;
    int len;
} LinkList;

//初始化一个表
void InitList(LinkList &L) {
    L.len = 0;
    L.head = L.tail = (LinkNodePtr)malloc(sizeof(LinkNode));
    L.head->next = NULL;
};

//寻找e元素在表中的位置
int FindLocate(LinkList &L, char e) {
    LinkNodePtr p;
    p = L.head->next;
    int locate = 1;
    // if(p) {
        for(;p && p->data < e; ) {
            p = p->next;
            locate++;
        }
    // }
    return locate;
};

//把元素插入表中，如果存在重复则不差入
bool ListInsert(LinkList &L, int locate, char e) {
    LinkNodePtr q;
    q = L.head;//0
    for(int i = 1; i < locate; i++) {
       q = q->next;
    }
    if(q->next && e == q->next->data) {
        return false;
    }
    else {
        LinkNodePtr p;
        p = (LinkNodePtr)malloc(sizeof(LinkNode));
        p->data = e;
        p->next = q->next;
        q->next = p;
        L.len++;
        return true;    
    }
};

//把元素推入L中
bool ListAppend(LinkList &L, char e) {
    LinkNodePtr p;
    p = (LinkNodePtr)malloc(sizeof(LinkNode));
    p->data = e;
    L.tail->next = p;
    L.tail = p;
    L.tail->next = NULL;
    L.len++;
    return true;
};

//输入一个集合
void CreateList(LinkList &L, int n) {
    char e;
    int locate;
    for(int i = 0; i < n; i++) {
        cin>>e;
        if(e >= 'a' && e <= 'z') {
            locate = FindLocate(L, e);
            ListInsert(L, locate, e);
        }
    }
};

//打印出一个集合
void ListTraverse(LinkList &L) {
    LinkNodePtr p;
    p = L.head->next;
    for(; p;) {
        cout<<p->data;
        p = p->next;
    }
    cout<<endl;
};

//判断两个元素是否相等
bool Equal(char a, char b) {
    if(a == b) {
        return true;
    }
    else {
        return false;
    }
};

//获取元素
void GetElem(LinkList &La, int i, char &e) {
    LinkNodePtr p;
    p = La.head->next;
    int j = 1;
    for(; j < i; j++) {
        p = p->next;
    }
    e = p->data;
};