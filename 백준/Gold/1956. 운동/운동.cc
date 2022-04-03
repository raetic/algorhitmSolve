#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cost[4001][4001];
int n, m;
int inf = 10000000;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cost[i][j] = inf;
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		cost[x][y] = z;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}

	}
	int maxi = inf;
	for (int i = 1; i <= n; i++) {
		if(cost[i][i]!=inf)
		maxi = min(maxi, cost[i][i]);
	}
	if (maxi == inf)cout << -1;
	else cout << maxi;
}