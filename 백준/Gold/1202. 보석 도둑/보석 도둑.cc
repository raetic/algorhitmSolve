#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	priority_queue<pair<int,int>> pq;
	priority_queue<int> bag;
	priority_queue<int> gc;
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ -x,y });
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		bag.push(-x);
	}
	for (int i = 0; i < m; i++) {
		while (!pq.empty()&&pq.top().first * -1 <= bag.top() * -1) {
			gc.push(pq.top().second);
			pq.pop();
		}
		bag.pop();
		if (gc.empty())continue;
		sum += gc.top();			
		gc.pop();
	}
	cout << sum;
}