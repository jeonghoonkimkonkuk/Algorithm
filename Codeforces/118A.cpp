#include<iostream>
#include<string.h>
using namespace std;
int main() {
	char a[102];
	cin >> a;
	for (int i = 0; i < strlen(a); i++) {
		a[i]=tolower(a[i]);
		if (a[i] != 'a'
			&& a[i] != 'e'
			&& a[i] != 'i'
			&& a[i] != 'o'
			&& a[i] != 'u'
			&& a[i] != 'y') {
			cout <<"."<< a[i];
		}
	}

}