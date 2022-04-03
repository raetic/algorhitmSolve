#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cost[501][501];
int n, m;
int inf = 100000000;
vector<int> v;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cost[i][j] = inf;

	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cost[x][y] = 1;

	}
	for (int i = 1; i <= n; i++) {
		cost[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}

	}
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] > 0 && cost[i][j] != inf)sum++;
			if (cost[j][i] > 0 && cost[j][i] != inf)sum++;
		}
		if (sum == n - 1)counter++;
	}
	cout << counter;
}