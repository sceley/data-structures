#include <iostream>
#include "HuffmanTree.h"
#include "Coder.h"

using namespace std;

int main() {
    int n;
    cout<<"输入数目"<<endl;
    cin>>n;
    char *ch = new char[n];
    int *weight = new int[n];
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

    char *en = new char[200];

    cout<<"输入需要编码的字符串"<<endl;
    cin.get();
    cin.get(en, 200);
    Coder(HC, en);
    delete []en;

    cout<<"输入需要译码的字符串"<<endl;
    char *de = new char[200];
    cin.get();
    cin.get(de, 200);
    Decoder(HT, de);
    delete []de;
    
    return 0;
};