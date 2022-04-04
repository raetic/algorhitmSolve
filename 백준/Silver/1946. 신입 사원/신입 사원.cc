#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
using namespace std;
int n;
int main() {
	int t;
	cin >> t;
	for (int aa = 0; aa < t; aa++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			pq.push({ x,y });
		}
		int counter = 1;
		int m1 = pq.top().first;
		int m2 = pq.top().second;
		pq.pop();
		while (!pq.empty()) {
			int x = pq.top().first;
			int y = pq.top().second;
			pq.pop();
			if (x > m1 && y > m2) {
				continue;
			}
			counter++;
			if (x < m1)m1 = x;
			if (y < m2)m2 = y;
		}
		cout << counter<<'\n';
	}
}