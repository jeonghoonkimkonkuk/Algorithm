#include<iostream>
#include<vector>

using namespace std;

vector<int> a[100005];
bool visit[100005];


double dfs(int pos) {
	int count = 0;
	double exLen=0;
	visit[pos] = true;
	for (int i = 0; i < a[pos].size(); i++) {
		if (!visit[a[pos][i]]) {
			count++;
			exLen += dfs(a[pos][i]);
		}
	}
	if (count == 0) 
		return 0;
	else
		return exLen / count + 1;



}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		visit[x] = false;
		visit[y] = false;
	}
	
	cout.precision(11);
	cout<<dfs(1);






}