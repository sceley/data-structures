#include <iostream>
#include <string.h>

using namespace std;

typedef char CourseName[3];

int main () {
	// string str = "helloworld";
	// char str1[11] = str;
	char str1[4] = {'c', 'h', 'd'}; 
	// char str2[4];
	// strcpy(str2, str1);
	// cout<<str2<<endl;

	CourseName str[3];
	strcpy(str[0], str1);
	for (int i = 0; str[i]; i++) {
		cout<<str[i];
	}
	return 0;
};