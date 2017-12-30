#include <iostream>
#include "Stack.h"
#include "ALGraph.h"
#include "Term.h"

using namespace std;

int main () {
	int term_count, max_grade;
	cout<<"请输入学期总数"<<endl;
	cin>>term_count;
	cout<<"请输入一学期的学分上限"<<endl;
	cin>>max_grade;

	ALGraph G;
	Stack S;
	CreateGraph(G);
	InitStack(S);
	TopologicalOrder(G, S);

	Term *terms = new Term[term_count];

	int j = 0, k = 0;
	terms[j].grades = 0;
	terms[j].length = 0;
	while (!StackEmpty(S)) {
		int i;
		Pop(S, i);
		if (terms[j].grades + G.vertices[i].grade < max_grade) {
			strcpy(terms[j].courses[k], G.vertices[i].data);
			terms[j].grades += G.vertices[i].grade;
			terms[j].length++;
			k++;
		} else {
			Push(S, i);
			j++;
			k = 0;
			terms[j].grades = 0;
			terms[j].length = 0;
		}
	}

	
	for (int i = 0; i < term_count; i++) {
		cout<<"第"<<i + 1<<"学期所修课程为:";
		for (int j = 0; j < terms[i].length; j++) {
			cout<<terms[i].courses[j]<<" ";
		}
		cout<<endl;
		cout<<"第"<<i + 1<<"学期所修学分为"<<terms[i].grades<<endl;
	}

	return 0;
};