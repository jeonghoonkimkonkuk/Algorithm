#include<iostream>
using namespace std;
int a[100005];
int d[100005];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	/*
	int left = 1;
	int right = 2;
	int max=a[left];
	int min = a[left];
	int dmax = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		right = a[i];
		if (max == min) {
			if (right == min - 1) {
				min--;
				d[i] = d[i - 1] + 1;
			}
			else{
				max++;
				d[i] = d[i - 1] + 1;
			}
		}
		else {
			if (right == min) {
				d[i] = d[i - 1] + 1;
			}
			else if (right == max) {
				d[i] = d[i - 1] + 1;
			}
			else{
				if (right == max + 1) {
					min++;
					max++;
				}
				else {
					min--;
					max--;
				}
				int j;
				for (j = i; j >= 1; j--) {
					if (a[j] == right + 2 || a[j] == right - 2)
						break;
				}
				j++;
				d[i] = d[i - 1] + 1 - (j - left);
				left = j;
			}
		}

		if (dmax < d[i])
			dmax = d[i];

	}
	cout << dmax;
	*/

#define max(a,b) a>b? a:b
	int dmax=2;
	d[a[1]] = 1;
	d[a[2]] = 2;
	for (int i = 3; i <= n; i++) {
		d[a[i]] = i;
		if (d[a[i] - 1] > d[a[i] + 1]) {
			if (d[a[i] - 2] > d[a[i] + 1]) {
				dmax = max(dmax, d[a[i]] - d[a[i] - 2]);
			}
			else {
				dmax = max(dmax, d[a[i]] - d[a[i] + 1]);
			}
		}
		else {
			if (d[a[i] + 2] > d[a[i] - 1]) {
				dmax = max(dmax, d[a[i]] - d[a[i] + 2]);
			}
			else {
				dmax = max(dmax, d[a[i]] - d[a[i] - 1]);
			}
		}
	}

	cout << dmax;
}