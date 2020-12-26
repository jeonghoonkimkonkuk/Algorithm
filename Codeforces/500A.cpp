#include<iostream>
using namespace std;

int main() {
	int n, t;
	int* a;
	bool ans=false;
	cin >> n >> t;
	a = new int[n - 1];
	for (int i = 0; i < n-1; i++) {
		cin >> a[i];
	}

	int cur=0;

	while (1) {
		cur += a[cur];
		if (cur + 1 == t) {
			ans = true;
			break;
		}
		if (cur + 1 > t) {
			break;
		}
	}

	if (ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}



	return 0;
}