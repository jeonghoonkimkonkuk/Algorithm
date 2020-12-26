#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int AA[100005];
int BB[100005];
int SS[100005];
int TT[100005];
int LL[100005];
int ans[100005];
int CNT[100005];

void LIS(int A[], int L[]) {
	vector<int> Last;
	vector<int>::iterator it;
	Last.push_back(-100);
	for (int i = 1; i <= N; i++) {
		if (Last.back() < A[i])
			Last.push_back(A[i]);
		it = lower_bound(Last.begin(), Last.end(),A[i]);
		*it = A[i];
		L[i] = it - Last.begin();
	}
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> AA[i];
	}
	LIS(AA, LL);
	int LEN = 0;
	for (int i = 1; i <= N; i++) {
		LEN = max(LEN, LL[i]);
	}
	for (int i = 1; i <= N; i++) {
		BB[N - i + 1] = 1000000 - AA[i];
	}
	LIS(BB, SS);
	for (int i = 1; i <= N; i++) {
		TT[N - i + 1] = SS[i];
	}
	for (int i = 1; i <= N; i++) {
		ans[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (LL[i] + TT[i] == LEN + 1) ans[i] = 3;
	}
	int maxi = 0;
	for (int i = 1; i <= N; i++) {
		if (ans[i] != 1) {
			if (AA[i] <= maxi) ans[i] = 2;
			maxi = max(maxi, AA[i]);
		}
	}
	int mini = 1000000;
	for (int i = N; i >= 1; i--) {
		if (ans[i] != 1) {
			if (AA[i] >= mini) ans[i] = 2;
			mini = min(mini, AA[i]);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i];
	}

	


}