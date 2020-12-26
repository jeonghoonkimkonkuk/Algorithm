

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

long long dist[400000];
long long train[400000];
using namespace std;  //(거리,정점)
struct node {
	long long cost, point;
	bool isTrain;
	node(long long len, long long point, bool isTrain)
		:cost(len), point(point),isTrain(isTrain) {};
};

struct cmp { //n1>n2
	bool operator()(node n1, node n2) {
		if (n1.cost > n2.cost) {
			return true;
		}
		else {
			if (n1.cost == n2.cost) {
				if (n1.isTrain == true && n2.isTrain == false)
					return true;
				else if (n1.isTrain == false && n2.isTrain == true)
					return false;
				else
					return false;
			}
			else {
				return false;
			}
		}
	}
};
vector<node> vt[400000];
int main() {
	long long ans = 0;
	priority_queue<node, vector<node>, cmp>pq;
	long long n, m, i, a, b, w,k;
	scanf("%lld %lld %lld", &n, &m,&k);
	ans = k;
	for (i = 1; i <= n; i++)
		dist[i] = -1;
	for (i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &a, &b, &w);
		vt[a].push_back(node(w, b,false));
		vt[b].push_back(node(w, a,false));
	}

	for (i = 1; i <= k; i++) {
		long long v, l;
		scanf("%lld %lld", &v, &l);
		vt[1].push_back(node(l, v,true));
		vt[v].push_back(node(l, 1,true));
	}
	pq.push(node(0, 1,false));
	while (pq.size()) {
		long long here = pq.top().point;
		long long cost = pq.top().cost;
		bool isTrain = pq.top().isTrain;
		pq.pop();
		if (dist[here] != -1)
			continue;
		dist[here] = cost;
		if (isTrain) ans--;
		
		for (auto it : vt[here]) {
			long long next = it.point;
			long long acost = it.cost + cost;
			bool isTrain = it.isTrain;
			if (dist[next] != -1)
				continue;
			pq.push(node(acost, next,isTrain));
		}
	}
	printf("%lld", ans);



}