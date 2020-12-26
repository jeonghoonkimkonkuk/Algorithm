#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct node_and_value {
	int node;
	int value;
};

bool dfs(vector<vector<node_and_value>>&nvs,int v,bool broken,vector<int>&ans) {
	bool find = false;
	nvs[v][0].node = -1;
	bool chfix=false;
	for (int i = 1; i <= nvs[v].size()-1; i++) {
		node_and_value& nv = nvs[v][i];
		if (nvs[nv.node][0].node == 0) {
			if (nv.value == 1) {
				chfix|=dfs(nvs, nv.node, false, ans);
			}
			if (nv.value == 2) {
				chfix|=dfs(nvs, nv.node, true, ans);
			}
		}
	}
	if ((!chfix) && (broken)) {
		ans.push_back(v);
		return true;
	}

	return chfix;

}

int main() {

	int n;
	vector<int> ans;
	cin >> n;
	vector<vector<node_and_value>> nvs;
	nvs.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		node_and_value nv = {0,0};
		nvs[i].push_back(nv);
	}
	for (int i = 1; i <= n-1; i++) {
		int x, y, value;
		cin >> x >> y >> value;
		node_and_value nv1 = { y,value };
		node_and_value nv2 = { x,value };
		nvs[x].push_back(nv1);
		nvs[y].push_back(nv2);
	}
	dfs(nvs, 1, false, ans);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<<" ";
	}



	return 0;
}