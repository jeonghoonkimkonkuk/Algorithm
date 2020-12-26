#include<iostream>
#include<algorithm>
using namespace std;
int a[200];
int main() {
	int N, i;
	long long ans = 0;
	int total = 0;
	int half;
	int sum;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
		total += a[i];
	}
	half = total / 2;

	sort(a, a + N);
	sum = 0;
	while (sum <= half) {
		sum += a[--i];
		ans++;
	}
	cout << ans << endl;
}