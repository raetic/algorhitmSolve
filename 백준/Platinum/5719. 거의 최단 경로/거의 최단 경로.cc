#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> edge[501];
vector<pair<int, int>> v1[501];
int n, m;
int dis[501];
int start;
int endt;
bool removev[501];

void DestroyRoad(int g) {	
	if(removev[g])return;
	removev[g] = true;
	for (int i = 0; i < v1[g].size(); i++) {			
			    edge[v1[g][i].first][v1[g][i].second].second = -1;					
			    if (v1[g][i].first != start)				
				DestroyRoad(v1[g][i].first); 
		}	
}
void dijkstra() {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,start });
	while(!pq.empty()) {		
		int d = pq.top().first;
		int x = pq.top().second;		
		pq.pop();
		if (d > dis[x])continue;
		for (int i = 0; i < edge[x].size(); i++) {
			if (edge[x][i].second == -1)continue;
			int da = d + edge[x][i].second;
			int v = edge[x][i].first;
			if (da < dis[v]) {				
				v1[v].clear();
				v1[v].push_back({ x, i });
				dis[v] = da;
				pq.push({ da,v });
			}
			else if (da == dis[v]) {
				
				v1[v].push_back({ x, i });
				
			}
		}
	}
}

int main() {
	cin >> n >> m;
	while (n != 0 && m != 0) {
		cin >> start >> endt;
		for (int i = 0; i < m; i++) {
			int x, y, d;
			cin >> x >> y >> d;
			edge[x].push_back({ y,d });
		}
		for (int i = 0; i < n; i++) {
			dis[i] = 500001;
		
		}
		int cdgr = 0;
		dis[start] = 0;
		dijkstra();		
		int gcdgr = dis[endt];
		
		DestroyRoad(endt);
		for (int i = 0; i < n; i++) {
			dis[i] = 500001;
			
		}
		dis[start] = 0;
		dijkstra();
		 gcdgr = dis[endt];	
		if (gcdgr == 500001)cout << -1 << '\n';
		else cout << gcdgr << '\n';
		for (int i = 0; i < n; i++) {
			edge[i].clear();
			v1[i].clear();
			removev[i] = false;
		}
		cin >> n >> m;
	}
}