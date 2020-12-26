#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005];
int b[1000005],d[1000005];
void quickSort(int start, int end) {
	if (start < end) {
		int pivotpos = (start + end) / 2;
		int pivot = a[pivotpos];
		swap(a[start], a[pivotpos]);
		swap(b[start], b[pivotpos]);

		int cursor = start;

		for (int i = start; i <= end; i++) {
			if (pivot > a[i]) {
				cursor++;
				swap(a[cursor], a[i]);
				swap(b[cursor], b[i]);
			}
		}

		swap(a[start], a[cursor]);
		swap(b[start], b[cursor]);

		quickSort(start, cursor - 1);
		quickSort(cursor + 1, end);
	}

}
int BinarySearch(int* arr, int len, int key) {
	int start = 1;
	int end = len;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			return mid-1;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}
int main() {
	int n;
	int max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	quickSort(1,n);
	for (int i = 1; i <= n; i++) {
		int tmp = BinarySearch(a, i, a[i] - b[i]);
		d[i] = 1 + d[tmp];
		if (max < d[i]) max = d[i];
	}
	cout << n-max;

	




}