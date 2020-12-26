#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


vector<int> edges[200005];
set<int> p;
int pSize;
bool visited[200005];

class node {
public:
	int num;
	int ans;
	int firstPath;
	int secondPath;
}a[200005];

bool isDamaged(int pos) {
	set<int>::iterator iter;
	iter = p.find(pos);
	if (iter != p.end())
		return true;
	else return false;
}

int dfs(int pos) {
	a[pos].firstPath = -2;
	a[pos].secondPath = -2;
	visited[pos] = true;
	int k = edges[pos].size();
	if (isDamaged(pos)) a[pos].firstPath = -1;
	for (int i = 0; i < k; i++) {
		if (!visited[edges[pos][i]]) {
			int path = dfs(edges[pos][i]);
			if (path > a[pos].firstPath) {
				a[pos].secondPath = a[pos].firstPath;
				a[pos].firstPath = path;
			}
			else if (path > a[pos].secondPath)
				a[pos].secondPath = path;
		}
	}
	if (a[pos].firstPath != -2) a[pos].num = a[pos].firstPath + 1;
	else a[pos].num = -2;
	//cout << pos << " " << a[pos].num << " "<<a[pos].firstPath<<" "<<a[pos].secondPath <<endl;
	return a[pos].num;
}


int dfs2(int pos, int fP) {
	int k = edges[pos].size();
	visited[pos] = true;
	int path = fP;
	if (path > a[pos].firstPath)
		a[pos].firstPath = path;
	else if (path > a[pos].secondPath)
		a[pos].secondPath = path;
	

	a[pos].ans = a[pos].firstPath+1;

	//cout << pos << " " << a[pos].num << " "<<a[pos].firstPath<<" "<<a[pos].secondPath <<endl;

	for (int i = 0; i < k; i++) {
		if (!visited[edges[pos][i]]) {
			if (a[pos].firstPath == a[edges[pos][i]].num) {
				if (a[pos].secondPath == -2) dfs2(edges[pos][i], -2);
				else dfs2(edges[pos][i], a[pos].secondPath + 1);
			}
			else {
				if(a[pos].firstPath==-2) dfs2(edges[pos][i], -2);
				else dfs2(edges[pos][i], a[pos].firstPath + 1);
			}

		}
	}
	return 0;
}



int main() {
	int n, m, d;
	cin >> n >> m >> d;
	pSize = m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		p.insert(tmp);
	}
	for (int i = 1; i <= n - 1; i++) {
		int p, q;
		cin >> p >> q;
		edges[p].push_back(q);
		edges[q].push_back(p);
	}

	//cout << "-------------" << endl;
	dfs(4);

	for (int i = 1; i <= n; i++) visited[i] = false;
	dfs2(4,-2);

	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].ans <= d) {
			num++;
		}
	}
	cout << num;
}