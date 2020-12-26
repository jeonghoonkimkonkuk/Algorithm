#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n;
	int n1, n2;
	bool forever = false;
	int winner;
	int count=0;
	deque<int> q1, q2;
	cin >> n;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		int c;
		cin >> c;
		q1.push_back(c);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		int c;
		cin >> c;
		q2.push_back(c);
	}

	while (1) {
		if (count > 1000) { //ÂóÂóÇÏ´Ù
			forever = true;
			break;
		}
		if (q1.size() == 0) {
			winner = 2;
			break;
		}
		if (q2.size() == 0) {
			winner = 1;
			break;
		}
		int a = q1.front();
		q1.pop_front();
		int b = q2.front();
		q2.pop_front();

		if (a > b) {
			q1.push_back(b);
			q1.push_back(a);
		}
		if (a < b) {
			q2.push_back(a);
			q2.push_back(b);
		}
		count++;
	}
	if (forever) {
		cout << "-1";
	}
	else {
		cout <<count<< " " << winner;
	}

}