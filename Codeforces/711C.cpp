#include<iostream>
using namespace std;
long long min(const long long& a, const long long& b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	int colorNum,treeNum,sectionNum;
	long long *c,** p;
	cin >> treeNum >> colorNum >> sectionNum;

	c = new long long [treeNum + 1] ;
	for (int i = 1; i <= treeNum; i++) {
		cin >> c[i];
	}
	p = new long long* [treeNum+1];
	for (int i = 0; i <= treeNum; i++) {
		p[i] = new long long[colorNum+1];
		if (i >= 1) {
			for (int j = 1; j <= colorNum; j++) {
				cin >> p[i][j];
			}
		}
	}

	long long*** dp = new long long**[treeNum+1];
	for (int i = 0; i <= treeNum; i++) {
		dp[i] = new long long*[sectionNum+1];
		for (int j = 0; j <= sectionNum; j++) {
			dp[i][j] = new long long[colorNum+1];
			for (int k = 0; k <= colorNum; k++) {
				if (i < j) {
					dp[i][j][k] = -1;
				}
				if (j == 0) {
					dp[i][j][k] = -1;
				}
			}
		}
	}
	for (int i = 0; i <= sectionNum; i++) {
		for (int j = 0; j <= colorNum; j++) {
			dp[0][i][j] = 0;
		}
	}





	for (int i = 1; i <= treeNum; i++) {
		for (int j = 1; j <= sectionNum; j++) {
			if (i >= j) {


				for (int k = 1; k <= colorNum; k++) {
					
						long long sameColor = dp[i - 1][j][k];
						long long difColorMin = LLONG_MAX;

						for (int m = 1; m <= colorNum; m++) {
							if (m != k && dp[i-1][j-1][m]!=-1) {
								difColorMin = min(difColorMin, dp[i - 1][j - 1][m]);
							}
						}

						if ((sameColor == -1 && difColorMin == LLONG_MAX) || (c[i] != 0 && k != c[i])) {
							dp[i][j][k] = -1;
						}
						else {
							if (sameColor == -1) {
								sameColor = LLONG_MAX;
							}
							dp[i][j][k] = min(sameColor, difColorMin) + p[i][k];
							if (k == c[i]) {
								dp[i][j][k] -= p[i][k];
							}
							//cout << sameColor << " : " << difColorMin << endl;
						}
						//cout << "dp" << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " = " << dp[i][j][k] << endl<<endl;
				}
			}
		}
	}

	long long min = LLONG_MAX;
	for (int j = 1; j <= colorNum; j++) {
			if (dp[treeNum][sectionNum][j] < min && dp[treeNum][sectionNum][j]!=-1) {
				min = dp[treeNum][sectionNum][j];
			}
	}

	if (min == LLONG_MAX) {
		min = -1;
	}

	cout << min;



	return 0;
}