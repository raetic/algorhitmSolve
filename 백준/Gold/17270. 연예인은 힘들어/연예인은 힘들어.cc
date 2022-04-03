#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cost[101][101];
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
		int x, y, z;
		cin >> x >> y >> z;
		cost[x][y] = min(cost[x][y],z);
		cost[y][x] = min(cost[y][x], z);

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
	int s, e;
	cin >> s >> e;
	int mini = inf;
	int mini2 = inf;
	int ys = -1;
	for (int i = 1; i <= n; i++) {
		if (i == s || i == e)continue;
		if (cost[s][i] + cost[e][i] < mini) {
			mini = cost[s][i] + cost[e][i];
			v.clear();
			v.push_back(i);
		}
		else if (cost[s][i] + cost[e][i] == mini) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (cost[s][v[i]] > cost[e][v[i]])continue;
		if (mini2 > cost[s][v[i]]) {
			mini2 = cost[s][v[i]];
			ys = v[i];
		}

	}
	cout << ys;
}