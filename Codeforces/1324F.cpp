#include<iostream>
#include<vector>

using namespace std;

vector<int> edges[200005];
vector<int> fromCh[200005];
bool visit[200005];



class node {
public:
	int bw, upMax,ans;
}a[200005];


int dfs(int pos) {
	int thisChild;
	int k = edges[pos].size();
	visit[pos] = true;
	a[pos].upMax = 0;
	for (int i = 0; i < k; i++) {
		if (!visit[edges[pos][i]]) {
			thisChild=dfs(edges[pos][i]);
			fromCh[pos][i] = thisChild;
			if (thisChild != -1) a[pos].upMax += thisChild;
		}
	}
	if (a[pos].bw) a[pos].upMax++;
	else a[pos].upMax--;
	return a[pos].upMax;
	

}

int dfs2(int pos, int fP) {
	int k = edges[pos].size();
	visit[pos] = true;
	if (fP != -1) a[pos].ans = a[pos].upMax + fP;
	else a[pos].ans = a[pos].upMax;
	for (int i = 0; i < k; i++) {
		if (!visit[edges[pos][i]]) {
			if (fromCh[pos][i] == -1) dfs2(edges[pos][i], a[pos].ans);
			else dfs2(edges[pos][i], a[pos].ans - fromCh[pos][i]);
		}
	}
	return 0;
}
int main() {
	long long ans;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].bw;
	for (int i = 1; i <= n-1; i++) {
		int p, q;
		cin >> p >> q;
		edges[p].push_back(q);
		edges[q].push_back(p);
		fromCh[p].push_back(0);
		fromCh[q].push_back(0);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) visit[i] = 0;
	dfs2(1,0);
	for (int i = 1; i <= n; i++) cout << a[i].ans<<" ";
	

}