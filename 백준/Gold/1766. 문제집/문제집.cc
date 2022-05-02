#include <iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int, vector<int>, greater<int>> d[32001];
int c[32001];
int n, m;
bool flag[32001];
vector<int> printV;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		d[x].push(y);
		c[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			flag[i] = true;
			pq.push(i);
			
		}
	}
	while (!pq.empty()) {
		int x = pq.top();
		printV.push_back(x);
		pq.pop();
		int k = d[x].size();
		for (int i = 0; i < k; i++) {
			if (!flag[d[x].top()]) {
				c[d[x].top()]--;
				if (c[d[x].top()] <= 0) {
				
					pq.push(d[x].top());
					flag[d[x].top()] = true;
				}
			}
			d[x].pop();
		}
	}
	for (int i = 0; i < n; i++)cout << printV[i]<<' ';
}