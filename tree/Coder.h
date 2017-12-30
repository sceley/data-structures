#include <iostream>
#include <cstring>

using namespace std;
struct HCnode {
	char ch;
	char *pstring;
};

struct HuffmanCoder {
	HCnode *hc;
	int hcsize;
};

void InitHuffmanCoder (HuffmanCoder &HC, int n) {
	HC.hc = new HCnode[n];
	HC.hcsize = n;
};
void CreateBook (HuffmanCoder &HC, HuffmanTree &HT) {
	int i, j, c, f, start;
	char *cd = new char[HC.hcsize];
	cd[HC.hcsize - 1] = '\0';
	for (i = 0; i < HC.hcsize; i++) {
		start = HC.hcsize - 1;
		HC.hc[i].ch = HT.ht[i].ch;
		for (c = i, f = HT.ht[i].parent; f != -1; c = f, f = HT.ht[f].parent) {
			if (HT.ht[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		cout<<HC.hc[i].ch<<" ";
		HC.hc[i].pstring = new char[HC.hcsize - start];
		for (j = start; j < HC.hcsize; j++) {
			HC.hc[i].pstring[j - start] = cd[j];
			cout<<cd[j];
		}
		cout<<endl;
	}
	delete []cd;
}
void Coder (HuffmanCoder &HC, char ch[]) {
	for (int i = 0; i < strlen(ch); i++) {
		for (int j = 0; j < HC.hcsize; j++) {
			if (ch[i] == HC.hc[j].ch) {
				for (int k = 0; HC.hc[j].pstring[k]; k++) {
					cout<<HC.hc[j].pstring[k];
				}
				break;
			}
		}
	}
	cout<<endl;
};
void Decoder (HuffmanTree &HT, char ch[]) {
	int i = 0, p, pre, root = HT.htsize - 1;
	pre = -1;
	p = root;
	while (i < strlen(ch)) {
		while (p != -1) {
			if (ch[i] == '0') {
				pre = p;
				p = HT.ht[p].lchild;
			} else {
				pre = p;
				p = HT.ht[p].rchild;
			}
			i++;
		}
		cout<<HT.ht[pre].ch;
		i--;
		pre = -1;
		p = root;
	}
	cout<<endl;
};