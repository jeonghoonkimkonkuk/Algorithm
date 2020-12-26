#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	long long l, r, min, incre;

}T[1000000];
long long A[200005];
long long N, M;
long long L, R, V;

long long build(long long k, long long L, long long R) {
	long long mid;
	T[k].l = L;
	T[k].r = R;
	T[k].incre = 0;
	if (L == R) { 
		T[k].min = A[L];
		return 0;
	}
	else {
		mid = (L + R) / 2;
		build(k * 2, L, mid);
		build(k * 2 + 1, mid + 1, R);
		T[k].min = min(T[k * 2].min + T[k * 2].incre, T[k * 2 + 1].min + T[k * 2 + 1].incre);
		return 0;
	}
}

long long query(long long k, long long L, long long R) {
	long long mid, lret, rret;
	if (T[k].l >= L && T[k].r <= R) {
		return T[k].min + T[k].incre;
	}
	else if (T[k].l > R || T[k].r < L) {
		return 5000000000000;
	}
	else {
		mid = (T[k].l + T[k].r) / 2;
		lret = query(k * 2, L, R);
		rret = query(k * 2 + 1, L, R);
		return min(lret, rret) + T[k].incre;
	}
}
long long increment(long long k, long long L, long long R, long long V) {
	long long mid, lret, rret;
	if (T[k].l >= L && T[k].r <= R) {
		T[k].incre += V;
		return 0;
	}
	else if (T[k].l > R || T[k].r < L) {
		return 0;
	}
	mid = (T[k].l + T[k].r) / 2;
	lret = increment(k * 2, L, R, V);
	rret = increment(k * 2 + 1, L, R, V);
	T[k].min = min(T[k * 2].min + T[k * 2].incre, T[k * 2 + 1].min + T[k * 2 + 1].incre);
	return 0;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	build(1, 1, N);
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> L; L++;
		cin >> R; R++;
		int c = getchar();
		if (c == '\n') {
			if (L <= R)
				cout << query(1, L, R) << endl;
			else {
				long long lret = query(1, 1, R);
				long long rret = query(1, L, N);
				cout << min(lret, rret) << endl;
			}
		}
		else {
			cin >> V;
			if (L <= R)
				increment(1, L, R, V);
			else {
				increment(1, 1, R, V);
				increment(1, L, N, V);
			}
		}
	}
}