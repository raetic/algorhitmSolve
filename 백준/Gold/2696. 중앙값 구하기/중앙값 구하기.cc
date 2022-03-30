#include <iostream>
#include<queue>
using namespace std;
int n;

int main() {
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		priority_queue <int, vector<int>> pq;

		vector<int> c;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			vector<int> v;
			int x;
			cin >> x;
			pq.push(x);
			if (i % 2 == 1) {
				for (int j = 0; j < i / 2; j++) {
					v.push_back(pq.top());
					pq.pop();
				}
				c.push_back(pq.top());
				for (int j = 0; j < i / 2; j++) {
					pq.push(v[j]);
				}
			}
		}

		cout << c.size() << '\n';

		for (int i = 0; i < c.size(); i++)cout << c[i] << ' ';
		cout << '\n';
	}
}