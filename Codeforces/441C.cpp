#include<iostream>
#include<vector>
using namespace std;

struct point {
	int x;
	int y;
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	point* arr;
	arr = new point[n * m];
	int count = 0;
	int curTube = 0;
	for (int i = 0; i < n; i++) {
		if (!(i % 2)) {
			for (int j = 0; j < m; j++) {
				point p = { i,j };
				arr[count++] = p;
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				point p = { i,j };
				arr[count++] = p;
			}
		}
	}
	
	count = 0;
	for (int i = 0; i < k-1; i++) {
		cout << "2 ";
		for (int j = 0; j < 2; j++) {
			cout << arr[count].x + 1 << " " << arr[count].y + 1 << " ";
			count++;
		}
		cout << endl;
	}

	cout << m * n - count << " ";
	for (int j = count; j < m * n; j++) {
		cout << arr[j].x + 1 << " " << arr[j].y + 1 << " ";
	}

	




	return 0;
}