#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[1001][1001];
int counter[1001][1001][2]; //1은 움직인 횟수,2는 벽 부순 횟수
bool flag[1001][1001][2]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	string k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = k[j-1]-48;
		}
	}
	queue<tuple<int, int, bool>> q;
	q.push({ 1,1,false });
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		bool b = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= m) {			
				if (b) {
					if (arr[x2][y2] == 0 && !flag[x2][y2][1]) {
						flag[x2][y2][1] = true;
						counter[x2][y2][1] = counter[x][y][1] + 1;
						q.push({ x2,y2,true });
					}
				}
				else {
					if (arr[x2][y2] == 1 && !flag[x2][y2][1]) {
						flag[x2][y2][1] = true;
						counter[x2][y2][1] = counter[x][y][0] + 1;
						q.push({ x2,y2,true });
					}
					if (arr[x2][y2] == 0 && !flag[x2][y2][0]) {
						flag[x2][y2][0] = true;
						counter[x2][y2][0] = counter[x][y][0] + 1;
						q.push({ x2,y2,false });
					}
				}
			}
		}
	}
	if (n == 1 && m == 1)cout << 1;
	else {
		if (counter[n][m][0] != 0 && counter[n][m][1] != 0) {
			cout << min(counter[n][m][0], counter[n][m][1]) + 1;
		}
		if (counter[n][m][0] == 0 && counter[n][m][1] != 0) {
			cout << counter[n][m][1] + 1;
		}
		if (counter[n][m][0] != 0 && counter[n][m][1] == 0) {
			cout << counter[n][m][0] + 1;
		}
		if (counter[n][m][0] == 0 && counter[n][m][1] == 0) {
			cout << -1;
		}
	}
}