#define STACK_INIT_SIZE 100

#include <iostream>

using namespace std;

typedef int SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;	
} Stack;

void InitStack (Stack &S) {
	S.base = new SElemType[STACK_INIT_SIZE];
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
};

void Push (Stack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
	} else {
		*S.top++ = e;
		// S.top++;
	}
};

void Pop (Stack &S, SElemType &e) {
	if (S.top == S.base) {
	} else {
		e = *--S.top;
	}
};

bool StackEmpty(Stack S) {
	if (S.top == S.base) {
		return true;
	} else {
		return false;
	}
};

void DisplayStack(Stack S) {
	for(; S.top != S.base;) {
		int i;
		Pop(S, i);
		cout<<i<<endl;
	}
};