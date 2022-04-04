#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	priority_queue<unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int>> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++) {
		unsigned long long int sum = 0;
		sum += pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		pq.push(sum);	
	}
	
	unsigned long long int sum = 0;
	while (!pq.empty()) {
		
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}