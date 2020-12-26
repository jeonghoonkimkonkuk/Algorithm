#include<iostream>
using namespace std;
int main() {

	int n;
	int one=0, two=0, three=0, four=0;
	int ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		switch (tmp) {
		case 1:one++; break;
		case 2:two++; break;
		case 3:three++; break;
		case 4:four++; break;
		}
	}
	ans += four;
	ans += three;
	if (three > one) one = 0;
	else one -= three;
	ans += (2*two + one) / 4;
	if ((2*two + one )%4!= 0) {
		ans++;
	}

	cout << ans << endl;
}