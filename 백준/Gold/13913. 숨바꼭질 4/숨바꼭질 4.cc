#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
#include<tuple>
using namespace std;
int n, m;
bool flag[100001];
int counter[100001];
int gr[100001];
int main() {
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	flag[n] = true;
	gr[n] = n;
	while (!q.empty()) {
		int x = q.front();
		if (x == m) {
			cout << counter[x]<<'\n';
			break;
		}
		q.pop();
		if (x - 1 >= 0 && !flag[x - 1]) {
			gr[x - 1] = x;
			flag[x - 1] = true;
			counter[x - 1] = counter[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 <= 100000 && !flag[x + 1]) {
			gr[x + 1] = x;
			flag[x + 1] = true;
			counter[x + 1] = counter[x] + 1;
			q.push(x + 1);
		}
		if (2 * x <= 100000 && !flag[2 * x]) {
			gr[2 * x] = x;
			flag[2 * x] = true;
			counter[2 * x] = counter[x] + 1;
			q.push(2 * x);
		}
	}
	int g = m;
	stack<int> nq;
	nq.push(m);
	while (g != n) {		
		g = gr[g];
		nq.push(g);
	}
	while (!nq.empty()) {
		cout << nq.top() << " ";
		nq.pop();
	}
}