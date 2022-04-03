#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> edge[801];
int n, m;
int dis[801];
int n1;
int n2;
bool flag[801];
int maxi = 2000000001;

void dijkstra(int s,int e) {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,s});
	dis[s] = 0;
	while(!pq.empty()) {		
		int d = pq.top().first;
		int x = pq.top().second;		
		pq.pop();
		if (flag[x])continue;
		
		for (int i = 0; i < edge[x].size(); i++) {
			int da = d + edge[x][i].second;
			int v = edge[x][i].first;
		    
			if (da < dis[v] && !flag[v]) {
				dis[v] = da;
				pq.push({ da,v });
			}
		}
	}
	
}
void clear() {
	for (int i = 1; i <= n; i++) {
		flag[i] = false;
		dis[i] = 2000000001;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back({ y,z });
		edge[y].push_back({ x,z });
	
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = 2000000001;
	}
	cin >> n1 >> n2;
	dijkstra(1, n);
	long long n1first=0;
	long long n2first=0;
	bool cantgo=false;

		n1first += dis[n1];
		if (dis[n1] == 2000000001)cantgo = true;
		clear();
		dijkstra(n1, n2);
		n1first += dis[n2];
		if (dis[n2] == 2000000001)cantgo = true;
		clear();
		dijkstra(n2, n);
		if (dis[n] == 2000000001)cantgo = true;
		n1first+= dis[n];
		clear();
		dijkstra(1, n);
			n2first += dis[n2];
			if (dis[n2] == 2000000001)cantgo = true;
			clear();
			dijkstra(n2, n1);
			n2first += dis[n1];
			if (dis[n1] == 2000000001)cantgo = true;
			clear();
			dijkstra(n1, n);
			n2first+= dis[n];		
			if (dis[n] == 2000000001)cantgo = true;
	
			if (cantgo)cout << -1;
			else
				cout << min(n1first, n2first);
}