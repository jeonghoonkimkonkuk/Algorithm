#include<iostream>
using namespace std;
#define max(a,b) (a>b?a:b)

int D[5000];
int main() {
	int n, a, b, c;
	long long ans;
	cin >> n >> a >> b >> c;
	D[0] = 0;


	for (int i = 1; i <= n; i++) {
		D[i] = -1;
		if (i - a >= 0 && D[i - a] >= 0) D[i] = D[i - a] + 1;
		if (i - b >= 0 && D[i - b] >= 0) D[i] = max(D[i], D[i - b] + 1);
		if (i - c >= 0 && D[i - c] >= 0) D[i] = max(D[i], D[i - c] + 1);
	}

	cout << D[n];
}