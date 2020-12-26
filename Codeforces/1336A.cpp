#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> edges[200005];
bool visit[200005];


class node {
public:
	int cnt, dist;
	bool operator < (const node& a) const {
		return dist - cnt < a.dist - a.cnt;
	}
}a[200005];

int dfs(int pos) {
	int k = edges[pos].size();
	int count = 0;
	visit[pos] = true;
	for (int i = 0; i < k; i++) {
		if (!visit[edges[pos][i]]) {
			a[edges[pos][i]].dist = a[pos].dist + 1;
			count+=dfs(edges[pos][i]);
		}
	}
	a[pos].cnt = count;
	return count + 1;
}
int main() {
	long long ans=0;
	int n, k, x, y;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	a[1].dist = 0;
	dfs(1); 
	sort(a + 1, a + n + 1);
	for (int j = n; j > n - k; j--)
		ans += a[j].dist - a[j].cnt;
	cout << ans;


}