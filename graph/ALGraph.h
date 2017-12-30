#include <iostream>
#include <string.h>

using namespace std;

#define MAX_VERTEX_NUM 20
#define MAX_NAME 3

// typedef char InfoType;

typedef char VertexType[MAX_NAME];

typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	// InfoType *info;
} ArcNode;

typedef struct VNode {
	VertexType data;
	int grade;
	ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	// int kind;
} ALGraph;

int LocateVex (ALGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (strcmp(u, G.vertices[i].data) == 0) {
			return i;
		}
	}
	return -1;
};

void CreateGraph (ALGraph &G) {
	cout<<"请输入课程个数"<<endl;
	cin>>G.vexnum;
	cout<<"请输入课程名称和课程学分"<<endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin>>G.vertices[i].data;
		cin>>G.vertices[i].grade;
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.vexnum; i++) {
		cout<<"请输入"<<G.vertices[i].data<<"课程的先修课"<<endl;
		VertexType firstCourse;
		while (cin>>firstCourse && firstCourse[0] != '0') {
			int location = LocateVex(G, firstCourse);
			ArcNode *p = new ArcNode();
			p->adjvex = location;
			p->nextarc = G.vertices[i].firstarc;
			G.vertices[i].firstarc = p;
			G.arcnum++;
		}
	}
};

void FindInDegree (ALGraph G, int *indegree) {
	for (int i = 0; i < G.vexnum; i++) {
		int count = 0;
		ArcNode *p;
		for (int j = 0; j < G.vexnum; j++) {
			if (j == i) {
				continue;
			}

			p = G.vertices[j].firstarc;
			while (p) {
				if (p->adjvex == i) {
					count++;
				}
				p = p->nextarc;
			}
		}
		indegree[i] = count;
	}
};

void TopologicalOrder (ALGraph G, Stack &T) {
	int *indegree = new int[G.vexnum];
	FindInDegree(G, indegree);
	Stack S;
	InitStack(S);
	for (int i = 0; i < G.vexnum; i++) {
		if (indegree[i] == 0) {
			Push(S, i);
		}
	}
	// count = 0;
	while (!StackEmpty(S)) {
		int e;
		Pop(S, e);
		Push(T, e);
		// ++count;
		ArcNode *p;
		for (p = G.vertices[e].firstarc; p; p = p->nextarc) {
			int k = p->adjvex;
			if (--indegree[k] == 0) {
				Push(S, k);
			}
		}
	}
};

void Display (ALGraph G) {
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode *p;
		cout<<i<<" ";
		for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
			int k = p->adjvex;
			cout<<"->"<<G.vertices[k].data;
		}
		cout<<endl;
	}
};