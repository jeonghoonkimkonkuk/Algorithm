#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<vector<unsigned>> v;
int main() {
	int n;
	unsigned* arr;
	cin >> n;
	arr = new unsigned[n+1];
	v.resize(n);
	int count = 0;

	map<int, int> m;
	
	

	for (int i = 0; i < n; i++) {
		unsigned x;
		cin >> x;

		if (m[x - 1] != 0) {
			if (m[x] != 0) {
				if (v[m[x] - 1].size() >= 1+v[m[x - 1] - 1].size()) {
					continue;
				}
				else {
					v[m[x] - 1].pop_back();
				}
			}
				arr[m[x - 1]] = x;
				m[x] = m[x - 1];
				m[x - 1] = 0;
				v[m[x] - 1].push_back(i + 1);
			
		}
		else {
			if (m[x] == 0) {

				m[x] = 1 + (count++);
				arr[m[x]] = x;
				v[m[x] - 1].push_back(i + 1);
			}



		}
	}


	//for (int i = 0; i < count; i++) {
	//	for (int j = 0; j < v[i].size(); j++) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "==============" << endl;
	unsigned max = 0, max_index = 0;
	for (int i = 0; i < n; i++) {
		if (max < v[i].size()) {
			max = v[i].size();
			max_index = i;
		}
	}

		cout << max << endl;
		for (int i = 0; i < v[max_index].size(); i++) {
			cout << v[max_index][i] << " ";
	}

	return 0;
}