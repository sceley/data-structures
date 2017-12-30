#include <iostream>

using namespace std;

typedef char VertexType[3];

int main () {
	VertexType firstInput;
	// firstInput = {0};
	while (cin>>firstInput && firstInput[0] != '0' ) {
		cout<<firstInput<<endl;
	}
	return 0;
}