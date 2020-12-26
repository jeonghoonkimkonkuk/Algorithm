
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct node {
	int l, r, cnt, lazy;

}T[26][400000];

char S[100005];
int N, M;
int L, R, V;

void pull_up(int t, int k) {
	T[t][k].cnt = T[t][2 * k].cnt + T[t][2 * k + 1].cnt;
}
void push_down(int t, int k) {
	int lazy = T[t][k].lazy;
	if (lazy == 0) {
		T[t][2 * k].lazy = 0;
		T[t][2 * k+1].lazy = 0;

		T[t][2 * k].cnt = 0;
		T[t][2 * k+1].cnt = 0;
	}
	else if (lazy == 1) {
		T[t][2 * k].lazy = 1;
		T[t][2 * k + 1].lazy = 1;
		T[t][2 * k].cnt = T[t][2 * k].r - T[t][2 * k].l + 1;
		T[t][2 * k + 1].cnt = T[t][2 * k + 1].r - T[t][2 * k + 1].l + 1;
	}
	T[t][k].lazy = -1;
}
void build(int t, int k, int L, int R) {
	int mid;
	T[t][k].l = L; T[t][k].r = R; T[t][k].lazy = -1;
	if (L == R) {
		if (S[L] - 'a' == t) T[t][k].cnt = 1;
		else T[t][k].cnt = 0;
	}
	else {
		mid = (L + R) / 2;
		build(t,k * 2, L, mid);
		build(t,k * 2 + 1, mid + 1, R);
		pull_up(t, k);
	}
}//

int query(int t,int k, int L, int R) {
	int mid, lret, rret;
	if (T[t][k].l >= L && T[t][k].r <= R) {
		return T[t][k].cnt;
	}
	else if (T[t][k].l > R || T[t][k].r < L) {
		return 0;
	}
	else {
		push_down(t, k);
		mid = (T[t][k].l + T[t][k].r) / 2;
		lret = query(t,k * 2, L, R);
		rret = query(t,k * 2 + 1, L, R);
		return lret + rret;
	}
}
void update(int t, int k, int L, int R, int V) {
	int mid;
	if (T[t][k].l >= L && T[t][k].r <= R) {
		T[t][k].lazy = V;
		if (V == 1)
			T[t][k].cnt = T[t][k].r - T[t][k].l + 1;
		else
			T[t][k].cnt= 0;
	}
	else if (T[t][k].l > R || T[t][k].r < L) {
	}
	else {
		mid = (T[t][k].l + T[t][k].r) / 2;
		push_down(t, k);
		update(t, k * 2, L, R, V);
		update(t, k * 2 + 1, L, R, V);
		//pull_up(t, k);
	}
}

int main() {
	int x, y, d;
	int left;
	int num[26];
	scanf("%d %d", &N, &M);
	scanf("%s", S + 1);// cin >> S + 1;
	for (int i = 0; i < 26; i++) {
		build(i, 1, 1, N);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 26; j++)
			num[j] = 0;
		scanf("%d %d %d", &x, &y, &d);//cin >> x >> y >> d;
		if (d == 1) {
			for (int j = 0; j < 26; j++) {
				num[j] = query(j, 1, x, y);
				update(j, 1, x, y, 0);
			}
			left = x;
			for (int j = 0; j < 26; j++) {
				if (num[j] > 0) {
					update(j, 1, left, left + num[j] - 1, 1);
					left = left + num[j];
				}
			}
		}
		else {
			for (int j = 0; j < 26; j++) {
				num[j] = query(j, 1, x, y);
				update(j, 1, x, y, 0);
			}
			left = x;
			for (int j = 25; j >= 0; j--) {
				if (num[j] > 0) {
					update(j, 1, left, left + num[j] - 1, 1);
					left = left + num[j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 26; j++) {
			char tmp = 'a' + j;
			if (query(j, 1, i, i) > 0) printf("%c", 'a' + j);//cout << tmp;
		}
	}
	printf("\n");
}