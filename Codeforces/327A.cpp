#include<iostream>
using namespace std;
int a[105];
int D[3][105];
#define max(a,b) a>b?a:b
int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	/* 가장 무식한 (n^3)
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int tmp = 0;
			for (int k = 1; k <= n; k++) {
				if (k<i || k>j)
					tmp += a[k];
				else
					tmp += 1 - a[k];
			}
			ans = max(ans, tmp);
		}
	}
	*/

	/* 조금 무식한 (n^2) : prefix 사용
	int prefix[105];
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int tmp = prefix[i-1]+prefix[n]-prefix[j]+(j-i+1)-(prefix[j] - prefix[i - 1]);
			ans = max(ans, tmp);
		}
	}
	*/

	// 가장 좋은 : Dynamic Programming
	for (int i = 1; i <= n; i++) {
		D[0][i] = D[0][i - 1]+a[i];
		D[1][i] = (max(D[0][i - 1], D[1][i - 1])) + (1 - a[i]);
		if(i>1) D[2][i] = (max(D[1][i - 1],D[2][i - 1]))+a[i];
	
	}
	ans = max(D[1][n], D[2][n]);
	cout << ans;
}
