#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	priority_queue<pair<int, int>> pq;
	priority_queue<int> pay;
	int max_day = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		max_day = max(y, max_day);
		pq.push({ y,x });
	}
	int d = 0;
	int sum = 0;
	for (int i = max_day; i >= 1; i--) {
		while (!pq.empty()&&i == pq.top().first)
		{
			pay.push(pq.top().second);
			pq.pop();
		}
		if (!pay.empty()) {
			sum += pay.top();
			pay.pop();
		}
		
	}cout << sum;
}