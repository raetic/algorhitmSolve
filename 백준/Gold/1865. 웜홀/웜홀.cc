#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
#include<tuple>
using namespace std;
vector<tuple<int, int, int>> edge;
int dist[501];
int n, m, w;
int MaxInt = 1000000000;
bool find() {
	for (int i = 1; i <= n; i++)dist[n] = -1;
	dist[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int x = get<0>(edge[j]);
			int y = get<1>(edge[j]);
			int z = get<2>(edge[j]);
			if (dist[x] == MaxInt)continue;
			if (dist[y] > dist[x] + z)dist[y] = dist[x] + z;
		}
	}
	for (int j = 0; j < edge.size(); j++) {
		int x = get<0>(edge[j]);
		int y = get<1>(edge[j]);
		int z = get<2>(edge[j]);
		if (dist[x] == MaxInt)continue;
		if (dist[y] > dist[x] + z) {
			return true;
		}
	}
	return false;
}
int main() {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			edge.push_back({ x,y,z });
			edge.push_back({ y,x,z });
		}
		for (int i = 0; i < w; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			edge.push_back({ x,y,-z });
		}
		if (find()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		edge.clear();
	}
}