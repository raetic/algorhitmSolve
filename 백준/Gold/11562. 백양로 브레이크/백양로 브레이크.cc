#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cost[251][251];
int n, m;
int inf = 100000000;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cost[i][j] = inf;

	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 1)
		{
			cost[y][x] = 0;
			cost[x][y] = 0;
		}
		else {
			cost[x][y] = 0;
			cost[y][x] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		cost[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (cost[j][k] > cost[j][i] + cost[i][k])
				{
					cost[j][k] = cost[j][i] + cost[i][k];
					
				}
			}

		}
	}
		
		int que;
		cin >> que;
		for (int i = 0; i < que; i++) {
			int x, y;
			cin >> x >> y;
		
			
			cout << cost[x][y] << '\n';
		}
	
}