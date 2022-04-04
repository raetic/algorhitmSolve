#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	priority_queue<long long , vector<long long >, greater<long long >> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		sum += pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		pq.push(sum);	
	}
	
	long long sum = 0;
	while (!pq.empty()) {
		
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}