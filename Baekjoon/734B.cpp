#include<iostream>
using namespace std;
int main() {

	int two, three, five, six,tfs;
	long long ans;
	cin >> two >> three >> five >> six;
	if (six < five) five = six;
	tfs = five;
	if (two < five) tfs = two;
	ans = (long long)256 * tfs;
	two -= tfs;
	if (three < two) two = three;
	ans += (long long)32 * two;
	cout << ans<<endl;
}