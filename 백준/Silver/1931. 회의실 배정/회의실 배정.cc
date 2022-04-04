#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>

using namespace std;
int n;
int main() {
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ y,x });
	}
	int counter = 0;
	int curEndTime=0;
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		if (curEndTime <= y) {
			curEndTime = x;
			counter++;



		}
	}
	cout << counter;
}