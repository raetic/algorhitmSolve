#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int base_map[21][21];
int n, m;
int maxi = 0;
void set(int b1, int b2) {
	bool flag[20][20];
	int map[20][20];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = base_map[i][j];
			flag[i][j] = false;
		}
	}
	map[b1 / m][b1 % m] = 1;
	map[b2 / m][b2 % m] = 1;
	int bcounter=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2&&!flag[i][j]) {
			
				bool E = false;
				int nbcounter=0;
				queue<pair<int, int>> q;
				q.push({ i,j });
				flag[i][j] = true;
				E = false;
				for (int d = 0; d < 4; d++) {
						int x2 = i + dx[d];
						int y2 = j + dy[d];
						if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m && map[x2][y2] == 0) { 
							
							E = true; }
					}
				while (!q.empty()) {
				
					nbcounter++;			
					int x = q.front().first;
					int y = q.front().second;					
					q.pop();
					for (int d = 0; d < 4; d++) {
						int x2 = x + dx[d];
						int y2 = y + dy[d];
						if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m) {
							if (map[x2][y2] == 2&&!flag[x2][y2]) {			
								flag[x2][y2] = true;							
								q.push({ x2,y2 });
                              }
							if (map[x2][y2] == 0) {
								E = true;									
							};
							if (map[x2][y2] == 1) {
								
							}
						}
					}
				
				}
				if (!E) { 
					bcounter += nbcounter; }
			}
		}
	}
	maxi = max(maxi, bcounter);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i <n; i++)
		for (int j = 0; j < m; j++)
			cin >> base_map[i][j];
	for (int i = 0; i < n * m-1; i++) {
		if (base_map[i / m][i % m] == 0) {
			for (int j = i + 1; j < n * m; j++) {
				if (base_map[j / m][j % m] == 0)
					set(i, j);
			}
		}
	}
	cout << maxi;
}