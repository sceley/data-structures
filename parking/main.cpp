#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
using namespace std;
int main () {
    int n;//停车场容量
    int carNumber;//汽车号码
    int time;//到达时间
    int _time;//离开时间
    char carInfo;//到达或离去
    SqStack S;//声明一个栈
    LinkQueue Q;//声明一个队列
    cout<<"请输入停车场容量"<<endl;
    cin>>n;
    InitStack(S, n);//初始化一个栈
    InitQueue(Q);//初始化一个队列
    while(cin>>carInfo>>carNumber>>time && carInfo != 'E'){
        if(carInfo == 'A') {
            if(S.top - S.base == S.stacksize) {
                EnQueue(Q, carNumber);//栈满，入队列
            }
            else {
                Push(S, carNumber, time);//入栈
            }
        }
        else if(carInfo == 'D') {
            Pop(S, Q, carNumber, time, _time);
            cout<<"汽车停车时间长为："<<time - _time<<endl;
        }
        else {
            cout<<"第一个信息请输入A或D"<<endl;
        }
    }
    return 0;
};