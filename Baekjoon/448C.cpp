#include<iostream>
using namespace std;
int a[5002];
int paintBricks(int start, int end, int floor) {
	if (start > end)
		return 0;
	int min = a[start];
	int ans=0;
	for (int i = start; i <= end; i++) {
		if (a[i] < min) min = a[i];
	}
	ans += min-floor;
	int s=start;
	for (int i = start; i <= end; i++) {
		if (a[i] == min) {
			ans += paintBricks(s, i - 1, min);
			s = i + 1;
		}
		else if (i == end) {
			ans += paintBricks(s, i, min);
		}
	}
	if (end-start + 1 < ans)
		return end-start + 1;
	else
		return ans;
	
}
int main() {
	int n;
	int ans;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ans=paintBricks(1, n, 0);
	cout << ans;


}