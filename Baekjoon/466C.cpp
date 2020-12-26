#include<iostream>
using namespace std;
int a[500005];
long long ans=0;
long long sum1, sum2, sum3,sum,sumd3;
long long p[500005];
long long toTheRight[500005];

int main() {

	int i,j,k,n;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	p[0] = 0;
	for (i = 1; i <= n; i++) {
		p[i] = p[i - 1] + a[i];
	}
	sum = p[n];
	if (sum % 3 != 0) {
		ans = 0;
	}
	else {
		sumd3 = sum / 3;
		k = 0;
		for (j = n - 1; j >= 2; j--) {
			if (p[j] == sumd3 * 2) k++;
			toTheRight[j] = k;
		}
		for (i = n - 2; i >= 1; i--) {
			if (p[i] == sumd3) {
				ans += toTheRight[i + 1];
			}
		}
	}
	cout << ans;
}