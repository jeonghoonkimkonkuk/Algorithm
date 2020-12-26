#include<iostream>
using namespace std;
int a[5005];
int p[5005];
double ans;
int main() {
	int i,j,n, k;
	cin >> n >> k;
	p[0] = 0;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}

	double max = 0;
	for (j = k; j <= n; j++) {
		for (i = j; i <= n; i++) {
			double tmp = (double)(p[i] - p[i - j]) / (double)j;
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	cout.fixed;
	cout.precision(12);
	cout << max;


}