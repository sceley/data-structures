#include <iostream>
using namespace std;
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree (BiTree &T) {
	char ch;
	cin>>ch;
	if(ch == ' ') {
		T = NULL;
	} else {
		if(!(T = (BiTree)malloc(sizeof(BiTNode)))) {
			exit(0);
		}
		else {
			T->data = ch;
			CreateBiTree(T->lchild);
			CreateBiTree(T->rchild);
		}
	}
};