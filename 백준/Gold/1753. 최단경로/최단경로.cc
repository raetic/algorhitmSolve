#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> edge[20001];
int n, m;
int dis[20001];
int start;

bool flag[20001];
void dijkstra() {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (flag[v])continue;
		flag[v] = true;
		for (int i = 0; i < edge[v].size(); i++) {
			int dis1 = d + edge[v][i].second;
			if (!flag[edge[v][i].first] && dis1 < dis[edge[v][i].first]) {
				dis[edge[v][i].first] = dis1;
				pq.push({ dis1,edge[v][i].first });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	cin >> start;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		edge[x].push_back({ y,d });
	}
	for (int i = 1; i <= n; i++)dis[i] = 1000000000;
	dis[start] = 0;
	dijkstra();
	for (int i = 1; i <= n; i++) {
		if (dis[i] != 1000000000)
			cout << dis[i] << '\n';
		else cout << "INF" << '\n';
	}
}