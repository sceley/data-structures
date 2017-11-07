#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "Operation.h"
using namespace std;

int main() {
    int n, m;
    LinkList La, Lb, Lc;

    InitList(La);
    cout<<"请输入集合A的初始化空间"<<endl;
    cin>>n;
    cout<<"请输入"<<n<<"个数据元素至集合A"<<endl;
    CreateList(La, n);
    // ListTraverse(La);

    InitList(Lb);
    cout<<"请输入集合B的初始化空间"<<endl;
    cin>>m;
    cout<<"请输入"<<m<<"个数据元素至集合B"<<endl;    
    CreateList(Lb, m);
    // ListTraverse(Lb);

    InitList(Lc); 

    cout<<"请输入您要选择的运算符"<<endl;
    cout<<"U代表并集"<<endl;
    cout<<"N代表交集"<<endl;
    cout<<"-代表减集"<<endl;
    char operation;
    cin>>operation;

    switch(operation) {
        case 'U':
            Sum(La, Lb, Lc);            
            break;
        case 'N':
            Intersection(La, Lb, Lc);
            break;
        case '-':
            Reduce(La, Lb, Lc);
            break;
    }
    ListTraverse(Lc);            
    return 0;
};