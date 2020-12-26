#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> Edges[105];
bool Visit[105];

void dfs(int pos) {
	int i, k;
	k = Edges[pos].size();
	Visit[pos] = true;
	for (i = 0; i < k; i++) {
		if (!Visit[Edges[pos][i]]) {
			dfs(Edges[pos][i]);
		}
	}
}

int X[1000], Y[1000];
int main() {
	int ans;
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i - 1; j++) {
			if (X[i]==X[j]||Y[i]==Y[j]) {
				Edges[i].push_back(j);
				Edges[j].push_back(i);
			}
		}
	}
	ans = 0;

	for (i = 1; i <= n; i++) {
		if (Visit[i] == 0) {
			dfs(i);
			ans++;
		}
	}

	printf("%d", ans - 1);




}