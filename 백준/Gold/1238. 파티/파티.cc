#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, o;
vector<pair<int, int>> v1[1001];
vector<pair<int, int>> v2[1001];
int di[1001];
bool flag[1001];
int di2[1001];
bool flag2[1001];
int main() {	
	cin >> n >> m >> o;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v1[y].push_back({ x,z });

		v2[x].push_back({ y,z });
	}
	
	
	for (int i = 1; i <= n; i++) {
		di[i] = 10000000;
		di2[i] = 10000000;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, o });
	di[o] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		
		if (flag[x])continue;
		flag[x] = true;		
		for (int i = 0; i < v1[x].size(); i++) {
			int dis = d + v1[x][i].second;
			if (!flag[v1[x][i].first] && dis < di[v1[x][i].first]) {
				di[v1[x][i].first] = dis;
			
				pq.push({dis,v1[x][i].first });
			}
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
	pq2.push({ 0, o });
	di2[o] = 0;
	while (!pq2.empty()) {
		int d = pq2.top().first;
		int x = pq2.top().second;
		pq2.pop();
		if (flag2[x])continue;
		flag2[x] = true;
		for (int i = 0; i < v2[x].size(); i++) {
			int dis = d + v2[x][i].second;
			if (!flag2[v2[x][i].first] && dis < di2[v2[x][i].first]) {
				
				di2[v2[x][i].first] = dis;
				pq2.push({ dis,v2[x][i].first });
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		maxi = max(di[i] + di2[i],maxi);
	}
	cout << maxi;

}