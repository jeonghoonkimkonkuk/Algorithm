#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool Visit[200000];
bool flour[200000];


struct node {
	int num, len;
	node(int num, int len) {
		this->num = num;
		this->len = len;
	}
};

vector<node> edges[200000];


int main() {
	int n, m, k;
	int i,j;
	int u, v, len;
	int ans = _CRT_INT_MAX;
	int a;
	scanf("%d %d %d", &n, &m, &k);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &u, &v, &len);
		edges[u].push_back(node(v, len));
		edges[v].push_back(node(u, len));
	}
	if (k > 0) {
		for (i = 1; i <= k; i++) {
			scanf("%d", &a);
			flour[a] = true;
		}

		for (i = 1; i <= n; i++) {
			if (flour[i]) {
				for (j = 0; j < edges[i].size(); j++) {
					if (!flour[edges[i][j].num])
						ans = min(ans, edges[i][j].len);
				}
			}
		}
	}
	if (ans == _CRT_INT_MAX) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}



}