#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<vector>

long long dist[400000];
long long from[400000];
bool visit[400000];
long long costs[400000];
long long nodes[400000];
using namespace std;
struct node {
	long long cost, point, from,ccost,num;
	node(long long len, long long point, long long from, long long num)
		:cost(len), point(point), from(from),num(num) {};

	node(long long len, long long point, long long from, long long ccost, long long num)
		:cost(len), point(point), from(from),ccost(ccost),num(num) {};
};

struct cmp {
	bool operator()(node n1, node n2) {
		if (n1.cost > n2.cost) {
			return true;
		}
		else if (n1.cost == n2.cost) {

			if (n1.ccost > n2.ccost) {
				return true;
			}
			else
				return false;
		}
		return false;
	}
};
vector<node> vt[400000];
int main() {
	long long ans=0;
	vector<long long> anss;
	priority_queue<node, vector<node>, cmp>pq;
	long long n, m, i, a, b, w,v;
	scanf("%lld %lld", &n, &m);
	for (i = 1; i <= n; i++)
		dist[i] = -1;
	for (i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &a, &b, &w);
		vt[a].push_back(node(w, b, a,i));
		vt[b].push_back(node(w, a, b,i));
	}
	scanf("%lld", &v);
	pq.push(node(0, v, v,0));
	while (pq.size()) {
		long long here = pq.top().point;
		long long cost = pq.top().cost;
		long long ffrom = pq.top().from;
		long long ccost = pq.top().ccost;
		long long num = pq.top().num;
		pq.pop();
		if (dist[here] != -1) {
			
			continue;
		}
		dist[here] = cost;
		from[here] = ffrom;
		costs[here] = ccost;
		nodes[here] = num;
		for (auto it : vt[here]) {
			long long next = it.point;
			long long acost = it.cost + cost;
			if (dist[next] != -1)
				continue;
			pq.push(node(acost, next, here,it.cost,it.num));
		}
	}
	if (dist[1] == -1) {
		printf("-1");
	}
	else {

		for (i = 1; i <=n; i++) {
			if (i != v) {
				long long now = i;
				visit[now] = true;
				ans += costs[now];
				anss.push_back(nodes[now]);
			}
		}

	}
	printf("%lld\n", ans);
	for (i = 0; i < anss.size(); i++) {
		printf("%lld ", anss[i]);
	}

}