#include<iostream>
#include<string.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a[102];
		cin >> a;
		int len = strlen(a);
		if (len <= 10) {
			cout << a<<endl;
		}
		else {
			cout << a[0] << len - 2 << a[len - 1]<<endl;
		}
	}

}