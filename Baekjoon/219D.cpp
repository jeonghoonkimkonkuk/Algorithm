#include<iostream>
#include<vector>

using namespace std;


vector<int> downEdges[200005];
vector<int> upEdges[200005];
bool visit[200005];
int min = INT_MAX;

class node {
public:
	int num;
	int ans;
}a[200005];


int dfs(int pos) {
	visit[pos] = true;
	a[pos].num = 0;
	int dk = downEdges[pos].size();
	int uk = upEdges[pos].size();
	for (int i = 0; i < dk; i++) {
		if (!visit[downEdges[pos][i]]) {
			a[pos].num += dfs(downEdges[pos][i]);
		}
	}
	for (int i = 0; i < uk; i++) {
		if (!visit[upEdges[pos][i]]) {
			a[pos].num += (dfs(upEdges[pos][i]) + 1);
		}
	}

	return a[pos].num;
}

int dfs2(int pos, int fP,bool ud) {// true-> down, false->up
	visit[pos] = true;
	if (ud) a[pos].ans = fP + 1;
	else a[pos].ans = fP - 1;

	if (a[pos].ans < min) min = a[pos].ans;

	int dk = downEdges[pos].size();
	int uk = upEdges[pos].size();
	for (int i = 0; i < dk; i++) {
		if (!visit[downEdges[pos][i]]) {
			dfs2(downEdges[pos][i],a[pos].ans,true);
		}
	}
	for (int i = 0; i < uk; i++) {
		if (!visit[upEdges[pos][i]]) {
			dfs2(upEdges[pos][i],a[pos].ans,false);
		}
	}

	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int p, q;
		cin >> p >> q;
		downEdges[p].push_back(q);
		upEdges[q].push_back(p);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) visit[i] = false;
	dfs2(1, a[1].num-1,true);
	cout << min << endl;
	for (int i = 1; i <= n; i++) {
		if (a[i].ans == min)
			cout << i << " ";
	}

}