#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>

using namespace std;
int n;
int main() {
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> a;
	priority_queue<int> b;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push(x);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a.top() * b.top();
		a.pop(); b.pop();
	}
	cout << sum;
}