#include<iostream>
#include<string>
using namespace std;
#define min(a,b) (a>b?b:a)


int c[100005];
string s[100005][2];
bool check[100005][4] = { false, };
long long d[100005][2];
int main() {
	int	n;
	
	s[0][0] = "";
	s[0][1] = "";
	check[0][0] = true;
	check[0][1] = true;
	check[0][2] = true;
	check[0][3] = true;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		//d[i][0] = INT_MAX;
		//d[i][1] = INT_MAX;

	}
	d[0][0] = 0;
	d[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
		if (check[i-1][0]||check[i-1][2]) {
			if (s[i][0].compare(s[i - 1][0]) >= 0) {
				check[i][0] = true;
			}
			if (s[i][1].compare(s[i - 1][0]) >= 0) {
				check[i][1] = true;
			}
		}
		if (check[i-1][1] || check[i-1][3]) {
			if (s[i][0].compare(s[i - 1][1]) >= 0) {
				check[i][2] = true;
			}
			if (s[i][1].compare(s[i - 1][1]) >= 0) {
				check[i][3] = true;
			}
		}

		if (!(check[i][0] || check[i][1] ||check[i][2] ||check[i][3])) {
			cout << "-1";
			return 0;
		}
		if (check[i][0] && check[i][2])
			d[i][0] = min(d[i - 1][0], d[i - 1][1]);
		else if(check[i][0] || check[i][2]) {
			if (check[i][0])
				d[i][0] = d[i - 1][0];
			else
				d[i][0] = d[i - 1][1];
		}

		if (check[i][1] && check[i][3])
			d[i][1] = min(d[i - 1][0], d[i - 1][1]) + c[i];
		else if(check[i][1] || check[i][3]){
			if (check[i][1])
				d[i][1] = d[i - 1][0] + c[i];
			else
				d[i][1] = d[i - 1][1] + c[i];
		}

	}
	if (check[n][0] || check[n][2]) {
		if (check[n][1] || check[n][3])
			cout << (min(d[n][0], d[n][1]));
		else
			cout << d[n][0];
	}
	else
		cout << d[n][1];


}