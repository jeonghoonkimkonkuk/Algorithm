#pragma warning(disable: 4996)

#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

struct arrData{
	long long num4=0;
	long long num7=0;
	long long ans7=0;
	long long ans=0;
};

struct node {
	arrData arrd[2];
	long long l=0, r=0;
	bool isSwitched = false;
}T[3000005];



char A[1000005];
long long N, M;
long long L, R;


arrData IncSub(const arrData& l, const arrData& r) {
	arrData p;
	for (int i = 0; i < 2; i++) {
		p.num4 = l.num4 + r.num4;
		p.num7 = l.num7 + r.num7;
		if (r.ans7 == 0) {
			p.ans7 = max((long long)0, l.ans7 + r.num7);
		}
		else {
			p.ans7 = max(l.num4 + r.ans7, l.ans7 + r.num7);
		}
		p.ans = max(p.num4, p.ans7);
	}
	return p;
}

void Build(long long k, long long L, long long R) {
	long long mid;

	T[k].l = L;
	T[k].r = R;
	if (L == R) {
		T[k].arrd[0].ans = 1;
		T[k].arrd[1].ans = 1;
		if (A[L] == '4') {
			T[k].arrd[0].num4 = 1;
			T[k].arrd[1].num7 = 1;
			T[k].arrd[1].ans7 = 1;
		}
		else {
			T[k].arrd[0].num7 = 1;
			T[k].arrd[0].ans7 = 1;
			T[k].arrd[1].num4 = 1;
		}
	}
	else {
		mid = (L + R) / 2;
		long long leftChild = k * 2;
		long long rightChild = k * 2 + 1;
		Build(leftChild, L, mid);
		Build(rightChild, mid + 1, R);
		
		T[k].arrd[0] = IncSub(T[leftChild].arrd[0], T[rightChild].arrd[0]);
		T[k].arrd[1] = IncSub(T[leftChild].arrd[1], T[rightChild].arrd[1]);

	}
	arrData& a = T[k].arrd[0];
	//cout << k << " " << a.num4 << " " << a.num7 << " " << a.ans7 << " " << a.ans << endl;
	//cout << "--" << T[k].l << T[k].r << endl;

}

arrData Count(long long k, long long L, long long R,bool Switch) {
	arrData lret, rret;

	bool switch_ = T[k].isSwitched ^ Switch;
	if (T[k].l >= L && T[k].r <= R) {
		return T[k].arrd[switch_];
	}
	else if (T[k].l > R || T[k].r < L) {
		return arrData();
	}
	else {

		lret = Count(k * 2, L, R, switch_);
		rret = Count(k * 2 + 1, L, R, switch_);

		arrData tmp = IncSub(lret, rret);
		//cout << k << " " << tmp.ans;

		return tmp;
	}
}

void Switch(long long k, long long L, long long R) {
	if (T[k].l >= L && T[k].r <= R) {
		T[k].isSwitched = !T[k].isSwitched;
	}
	else if (T[k].l > R || T[k].r < L) {

	}
	else {

		long long leftChild = k * 2;
		long long rightChild = k * 2 + 1;
		Switch(leftChild, L, R);
		Switch(rightChild, L, R);
		
		arrData l,l_s;
		arrData r,r_s;
		l = T[leftChild].arrd[T[leftChild].isSwitched];
		l_s = T[leftChild].arrd[!T[leftChild].isSwitched];

		r = T[rightChild].arrd[T[rightChild].isSwitched];
		r_s = T[rightChild].arrd[!T[rightChild].isSwitched];

		T[k].arrd[0] = IncSub(l, r);
		T[k].arrd[1] = IncSub(l_s, r_s);
	}
}

int main() {
	scanf("%lld", &N);
	scanf("%lld", &M);
	scanf("%s", (A + 1));
	Build(1, 1, N);
	//printTree(1, 1, N);
	//cout << Count(1, 1, N).ans;


	for (int i = 0; i < M; i++) {
		char c[10];
		scanf("%s", c);
		if (c[0] == 's') {
			long long a, b;
			scanf("%lld %lld", &a, &b);
			Switch(1, a, b);
			//printTree(1, 1, N);
		}
		else {
			printf("%lld\n", Count(1, 1, N, false).ans);
		}
	}



}