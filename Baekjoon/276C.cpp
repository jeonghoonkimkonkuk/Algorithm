#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;


long long n, q;
struct node {
	long long l, r, cnt;
}T[800005];
long long A[200005];
long long Times[200005];

void build(long long k, long long l, long long r) {
	long long mid;
	T[k].l = l;
	T[k].r = r;
	T[k].cnt = 0;
	if (l == r) {

	}
	else {
		mid = (l + r) / 2;
		build(k * 2, l, mid);
		build(k * 2 + 1, mid + 1, r);
	}
}

void query(long long k, long long l, long long r) {
	if (T[k].l >= l && T[k].r <= r) {
		T[k].cnt++;
	}
	else if (T[k].l > r || T[k].r < l) {

	}
	else {
		query(k * 2, l, r);
		query(k * 2 + 1, l, r);
	}
}
void getTime(long long k, long long v,long long fromP) {
	if (T[k].l == v && T[k].r == v) {
		Times[v-1]=fromP + T[k].cnt;
	}
	else if (T[k].l > v || T[k].r < v) {

	}
	else {
		getTime(k * 2, v,fromP+T[k].cnt);
		getTime(k * 2 + 1, v, fromP + T[k].cnt);
	}
}
int main() {
	long long i,l,r,ans=0;
	scanf("%I64d %I64d", &n, &q);
	build(1,1,n);
	for (i = 0; i < n; i++) {
		scanf("%I64d", &A[i]);
	}
	for (i = 0; i < q; i++) {
		scanf("%I64d %I64d", &l, &r);
		query(1, l, r);
	}
	for (i = 0; i < n; i++) {
		getTime(1, i+1,0);
	}
	sort(A, A + n);
	sort(Times, Times + n);
	for (i = 0; i < n; i++) {
		ans += A[i] * Times[i];
	}
	printf("%I64d", ans);

}