#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
int n, m;
int bs[301][301];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool flag[301][301];
int getIceCount() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			flag[i][j] = false;
		}
	}
	int iceCount = 0;
	queue<pair<int,int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (bs[i][j] > 0&&!flag[i][j]) {
				iceCount++;
				q.push({ i,j });
				flag[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int x1 = x + dx[i];
						int y1 = y + dy[i];
						if (x1 > 0 && y1 > 0 && x1 <= n && y1 <= m && !flag[x1][y1] && bs[x1][y1] > 0) {
							flag[x1][y1] = true;
							q.push({ x1, y1 });
						}
					}
				}
			}
		}
	}
	return iceCount;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> bs[i][j];
		}
	}
	int c = getIceCount();
	int counter = 0;
	while (c == 1) {
		int minus[301][301];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				minus[i][j] = 0;
				if (bs[i][j] > 0) {
					for (int k = 0; k < 4; k++) {
						if (bs[i + dx[k]][j + dy[k]] == 0) {
							minus[i][j]++;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				bs[i][j] -= minus[i][j];
				if (bs[i][j] < 0)bs[i][j] = 0;
			}
		}
		c = getIceCount();
		counter++;
	}
	if (c == 0)cout << c;
	else cout << counter;
}