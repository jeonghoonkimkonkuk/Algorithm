#include<iostream>
using namespace std;

long long a[100005];
long long p1[100005];
long long p2[100005];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		bool find = false;
		int n;
		cin >> n;
		p1[0] = 0;
		p2[n+1] = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			p1[j] = p1[j - 1] + a[j];
		}
		for (int j = n; j >= 1; j--) {
			p2[j] = p2[j + 1] + a[j];
		}
		for (int j = 1; j <= n; j++) {
			if (p1[j]<=0 || p2[n + 1 - j] <= 0) {
				cout << "NO"<<endl;
				find = true;
				break;
			}
		}
		if (find == false) {
			cout << "YES"<<endl;
		}



	}


}