#include<iostream>

using namespace std;

#define max 10000;

struct HTnode {
	char ch;
	int weight, parent, lchild, rchild;
};

struct HuffmanTree {
	HTnode *ht;
	int htsize;
};

void initHuffmanTree (HuffmanTree &HT, int n) {
	HT.htsize = 2 * n - 1;
	HT.ht = new HTnode[2 * n -1];
};
int MinVal(HuffmanTree &HT, int i) {
	int j, k, min = max;
	for (j = 0; j < i; j++) {
		if (HT.ht[j].parent == -1 && HT.ht[j].weight < min) {
			min = HT.ht[j].weight;
			k = j;
		}
	}
	HT.ht[k].parent = max;
	return k;
};

void Select(HuffmanTree &HT, int i, int &s1, int &s2) {
	int s;
	s1 = MinVal(HT, i);
	s2 = MinVal(HT, i);
	if (s1 > s2) {
		s = s1,
		s1 = s2;
		s2 = s;
	}
};

void Create(HuffmanTree &HT, int n, char ch[], int weight[]) {
	int i, s1, s2;
	if (n > 1) {
		for (i = 0; i < n; i++) {
			HT.ht[i].ch = ch[i];
			HT.ht[i].weight = weight[i];
			HT.ht[i].parent = -1;
			HT.ht[i].lchild = -1;
			HT.ht[i].rchild = -1;
		}
		for (; i < HT.htsize; i++) {
			Select(HT, i, s1, s2);
			HT.ht[s1].parent = HT.ht[s2].parent = i;
			HT.ht[i].lchild = s1;
			HT.ht[i].rchild = s2;
			HT.ht[i].weight = HT.ht[s1].weight + HT.ht[s2].weight;
			HT.ht[i].parent = -1;
			HT.ht[i].ch = ' ';
		}
	}
};

int Deepth(HuffmanTree HT) {
	int n;
	int location;
	int min = max;
	for(n = 0; 2 * n - 1 < HT.htsize; n++) {
	}
	for(int i = 0; i < n; i++) {
		if(HT.ht[i].weight < min) {
			min = HT.ht[i].weight;
			location = i;
		};
	}
	HTnode f;
	int i;
	for(i = 1, f = HT.ht[location]; f.parent != -1; i++) {
		f = HT.ht[f.parent];
	}
	return i;
};
// void Display(HuffmanTree HT, HTnode ht, Link link, int i) {
// 	if(ht.ch) {
// 		for(int k = 0; link[i].string[k]; k++) {

// 		}
// 		cout<<ht.weight<<endl;
// 		i++;
// 		Display(HT, HT.ht[ht.lchild], link, i);
// 		Display(HT, HT.ht[ht.rchild], link, i);
// 	}
// 	int deepth = Deepth(HT);
// 	cout<<"deepth"<<deepth<<endl;
// };