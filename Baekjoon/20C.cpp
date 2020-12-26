#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

int dist[200000];
int from[200000];
using namespace std;  //(거리,정점)
struct node {
	int cost, point, from;
	node(int len, int point, int from)
		:cost(len), point(point), from(from) {};
};

struct cmp {
	bool operator()(node n1, node n2) {
		return n1.cost < n2.cost;
	}
};
vector<node> vt[200000];
int main(){
	priority_queue<node,vector<node>,cmp>pq;
	int n, m,i,a,b,w;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		dist[i] = -1;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		vt[a].push_back(node(w,b,a));
		vt[b].push_back(node( w,a,b ));
	}
	pq.push(node( 0,n,n));
	while (pq.size()) {
		int here = pq.top().point;
		int cost = -pq.top().cost;
		int ffrom = pq.top().from;
		pq.pop();
		if (dist[here] != -1)
			continue;
		dist[here] = cost;
		from[here] = ffrom;
		for (auto it : vt[here]) {
			int next = it.point;
			int acost = -it.cost - cost;
			if (dist[next] != -1)
				continue;
			pq.push(node( acost,next,here ));
		}
	}

	if (dist[1] == -1) {
		printf("-1");
	}
	else {

		int now = 1;
		while (now != n) {
			printf("%d ", now);
			now = from[now];
		}
		printf("%d", n);

	}




}