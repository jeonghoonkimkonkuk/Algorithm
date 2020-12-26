#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b

int a[100005];
long long D[100005][2];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	for (int i = 1; i <= 100000; i++) {
			D[i][0] = max(D[i - 1][0], D[i - 1][1]);
			D[i][1] = D[i - 1][0] + (long long)i*a[i];
	}
	cout << (max(D[100000][0], D[100000][1]));

}