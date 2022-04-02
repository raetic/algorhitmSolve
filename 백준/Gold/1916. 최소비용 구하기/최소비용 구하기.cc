#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, long long>> edge[100001];
int n, m;
long long dis[100001];
int start;

bool flag[20001];
void dijkstra() {
	priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		long long d = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (flag[v])continue;
		flag[v] = true;
		for (int i = 0; i < edge[v].size(); i++) {
			long long dis1 = d + edge[v][i].second;
			if (!flag[edge[v][i].first] && dis1 < dis[edge[v][i].first]) {
				dis[edge[v][i].first] = dis1;
				pq.push({ dis1,edge[v][i].first });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		long long d;
		cin >> x >> y >> d;
		edge[x].push_back({ y,d });
	}
	for (int i = 1; i <= n; i++)dis[i] = 10000000000;
	int endn;
	cin >> start >> endn;
	dis[start] = 0;
	dijkstra();
	cout << dis[endn];
}