#include <iostream>
#include "Stack.h"
#include "ALGraph.h"

using namespace std;

int main () {
	// int vexnum, arcnum;
	int term;
	cout<<"请输入学期总数"<<endl;
	cin>>term;
	int maximun;
	cout<<"请输入一学期的学分上限"<<endl;
	cin>>maximun;
	ALGraph G;
	CreateGraph(G);
	// Display(G);
	Stack S;
	InitStack(S);
	TopologicalOrder(G, S);
	// DisplayStack(S);
	int sum = 0;
	int j = 0;
	while (!StackEmpty(S)) {
		int i;
		Pop(S, i);
		// cout<<i<<endl;
		if (sum + G.vertices[i].grade < maximun) {
			sum += G.vertices[i].grade;
			cout<<G.vertices[i].data<<" ";
		} else {
			cout<<j + 1<<"学期所修学分为"<<sum<<endl;
			sum = 0;
			j++;
			cout<<G.vertices[i].data<<" ";
			sum += G.vertices[i].grade;
		}
	}
	cout<<j + 1<<"学期所修学分为"<<sum<<endl;
	return 0;
};