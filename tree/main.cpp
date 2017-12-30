#include <iostream>
#include "HuffmanTree.h"
#include "Coder.h"
#include "Link.h"

using namespace std;

int main() {
    int n;
    cout<<"输入数目"<<endl;
    cin>>n;
    char *ch;
    ch = new char[n];
    int *weight;
    weight = new int[n];
    for(int i = 0; i < n; i++) {
    	cout<<"请输入第"<<i + 1<<"个字符及权值"<<endl;
    	cin.get();
    	ch[i] = cin.get();
    	cin>>weight[i];
    	cout<<ch[i]<<' '<<weight[i]<<endl;
    }
    HuffmanTree HT;
    initHuffmanTree(HT, n);
    Create(HT, n, ch, weight);
    HuffmanCoder HC;
    InitHuffmanCoder(HC, n);
    CreateBook(HC, HT);
    delete []ch;
    // ch = new char[n + 1];
    // cin.get();
    // cin.get(ch, n + 1);
    // Coder(HC, ch);
    // char *de = new char[4];
    // de[0] = '1';
    // de[1] = '1';
    // de[2] = '1';
    // de[3] = '0';
    // Decoder(HT, de);
    return 0;
};