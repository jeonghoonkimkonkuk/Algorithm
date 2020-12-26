#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
map<string, vector<string>> m;
map<string, bool> visit;


int dfs(string s) {
	int count = 0;
	for (int i = 0; i < m[s].size(); i++) {
		int cnt = dfs(m[s][i]);
		if (cnt > count)
			count = cnt;
	}
	return count + 1;
}

int main() {
	int n;
	cin >> n;
	string start;
	for (int i = 0; i < n; i++) {
			string x,reposted, y;
			cin >> x;
			cin >> reposted;
			cin >> y;

			
			transform(x.begin(), x.end(), x.begin(), tolower);
			transform(y.begin(), y.end(), y.begin(), tolower);

			m[y].push_back(x);
			if (i == 0)
				start = y;
		
			visit[x] = false;
	}
	cout<<dfs(start);
	
}