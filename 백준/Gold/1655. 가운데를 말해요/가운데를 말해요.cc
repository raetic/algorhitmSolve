#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>> pq1; //얘는 큰 순으로
	priority_queue<int, vector<int>, greater<int>> pq2; //얘는 작은 순으로
	cin >> n;
	int mid;
	int x;
	cin >> x;
	mid = x;
	cout << mid << '\n';
	for (int i = 1; i < n; i++) {	
		cin >> x;
		if (x < mid) {
			pq1.push(x);
		}
		else {
			pq2.push(x);
		}
		if (pq1.size() > pq2.size()) {
			pq2.push(mid);
			mid = pq1.top();
			pq1.pop();
		}
		else if (pq1.size() == pq2.size() - 2) {
			pq1.push(mid);
			mid = pq2.top();
			pq2.pop();
		}
		cout << mid << '\n';
	}
}