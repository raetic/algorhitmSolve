#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n, m;
bool arr[10001];
bool flag[10001];
int counter[10001];
bool s[10001];
int main() {
	int t;
	for (int i = 2; i <= 10000; i++) {
			if (!arr[i]) {
				s[i] = true;
				for (int j = 1; j * i <= 10000; j++) {

					arr[i * j] = true;
				}
			}
		}
	cin >> t;
	for (int aa = 0; aa < t; aa++) {
		
		for (int i = 1; i <= 10000; i++) {
			counter[i] = 0;
			flag[i] = false;
		}
		cin >> n >> m;
		queue<int> q;
		flag[n] = true;
		q.push(n);
		while (!q.empty()) {
			if (q.front() == m)break;
			int base = q.front();
			int b = base;
			q.pop();
			int x[4];
			int counter2 = 0;
			while (b != 0) {
				x[counter2] = b % 10;
				b /= 10;
				counter2++;
			}
			for (int i = 1; i <= 9; i++) {
				int y = i * 1000 + x[2] * 100 + x[1] * 10 + x[0];
				if (!flag[y] && s[y]) {
					flag[y] = true;
					q.push(y);
					counter[y] = counter[base] + 1;
				}
			}
			for (int i = 0; i <= 9; i++) {
				int y = x[3] * 1000 + i * 100 + x[1] * 10 + x[0];
				if (!flag[y] && s[y]) {
					flag[y] = true;
					q.push(y);
					counter[y] = counter[base] + 1;
				}
			}
			for (int i = 0; i <= 9; i++) {
				int y = x[3] * 1000 + x[2] * 100 + i * 10 + x[0];
				if (!flag[y] && s[y]) {
					flag[y] = true;
					q.push(y);
					counter[y] = counter[base] + 1;
				}
			}
			for (int i = 0; i <= 9; i++) {
				int y = x[3] * 1000 + x[2] * 100 + x[1] * 10 + i;
				if (!flag[y] && s[y]) {
					flag[y] = true;
					q.push(y);
					counter[y] = counter[base] + 1;
				}
			}
		}
		if (counter[m] == 0 && n != m)cout << "Impossible\n";
		cout << counter[m]<<'\n';
	}
}