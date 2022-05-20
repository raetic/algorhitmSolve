#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
bool flag[3001];
int counter[3001];
int h;
int t;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		if (a == 'H')h++;
	}
	for (int i = 0; i <= n; i++)counter[i] = -1;
	queue<int> q;
	flag[h] = true;
	q.push(h);	
	counter[h] = 0;
	while (!q.empty()) {
		h = q.front();
		t = n - h;
		q.pop();
		if (h == 0)break;
		for (int i = 0; i <= m; i++) {
			int h2 = h - i;
			int t2 = t - (m-i);
			if (h2 < 0 || t2 < 0)continue;
			h2 += (m - i);
			t2 += i;
			if (h2 >= 0 && t2 >= 0 && h2 <= n && t2 <= n && !flag[h2]) {				
				flag[h2] = true;
				counter[h2] = counter[h] + 1;
				q.push(h2);
			}
		}
}
	cout << counter[0];
	
}