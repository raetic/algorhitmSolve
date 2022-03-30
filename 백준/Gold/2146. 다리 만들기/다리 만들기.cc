#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[101][101];
int n;
bool flag[101][101];
int dis[101][101];
bool visit[101][101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int c = 2;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				map[i][j] = c;
				q.push({ i,j });
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					bool isE = true;
					for (int k = 0; k < 4; k++) {
						int x2 = x + dx[k];
						int y2 = y + dy[k];
						if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && map[x2][y2] == 1) {

							map[x2][y2] = c;
							q.push({ x2,y2 });
						}if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && map[x2][y2] == 0)
							isE = false;
					}
					if (!isE)flag[x][y] = true;
				}
				c++;
			}
		}
	}
	int mini = 100000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int a = 1;a<= n; a++) {
				for (int b = 1; b <= n; b++) {
					visit[a][b] = false;
				}
			}
			if (flag[i][j]) {
				queue<pair<int, int>> q2;
				c = map[i][j];
				q2.push({ i,j });
				dis[i][j] = 0;
				while (!q2.empty())
				{
					int x = q2.front().first;
					int y = q2.front().second;
					q2.pop();
					bool isE = false;
					for (int k = 0; k < 4; k++) {
						int x2 = x + dx[k];
						int y2 = y + dy[k];
					  if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && map[x2][y2] != 0 && map[x2][y2] != c)
						{
							
							mini = min(mini, dis[x][y]);
							isE = true;
							break;
						}
						if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && map[x2][y2] == 0&&!visit[x2][y2]) {
							visit[x2][y2] = true;
							dis[x2][y2] = dis[x][y] + 1;
							q2.push({ x2,y2 });
						}
						
					}
					if (isE)break;
				}
			}
		}
	}
	cout << mini;
}