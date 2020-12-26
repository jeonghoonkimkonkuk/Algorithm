#include<iostream>
using namespace std;
int arr[52];
long long int bitarr[2][52];
long long int findones(long long int n, int size) {
	if (n <= 0)
		return 0;
	else {
		int i;
		for (i = 1; i <= size; i++) {
			if (bitarr[0][i] == n) {
				return bitarr[1][i];
			}
			if (bitarr[0][i] > n)
				break;
		}
		return bitarr[1][i-1] + arr[i] + findones(n - bitarr[0][i-1]-1, size);
	}
}
int main() {
	long long int n, l, r;
	cin >> n >> l >> r;
	int size=0;
	if (n == 0)
		size = 1;
	else {
		for (int i = 1; n > 0; i++) {
			arr[i] = n % 2;
			n /= 2;
			size++;
		}
	}
	for (int i = 1; i <= size/2; i++) {
		int temp;
		temp = arr[size - i + 1];
		arr[size - i + 1] = arr[i];
		arr[i] = temp;
	}


	bitarr[0][0] = 0;
	bitarr[1][0] = 0;
	for (int i = 1; i <= size; i++) {
		bitarr[0][i] = bitarr[0][i - 1] * 2 +1;
		bitarr[1][i] = bitarr[1][i - 1] * 2 + arr[i];
	}
	
	cout << findones(r, size) - findones(l - 1, size);



}