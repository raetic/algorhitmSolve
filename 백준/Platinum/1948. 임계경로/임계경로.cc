#include <iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int n, m, s, e;
vector<tuple<int, int, int>> v[100001];//길
vector<tuple<int,int,int>> rev[100001];
int d[100001];
bool flag[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y,z;
		cin >> x >> y>>z;
		v[x].push_back({ y,z,i });
		rev[y].push_back({ x,z,i });
		
	}
	cin >> s >> e;
	queue<pair<int,int>> q;
	q.push({ s,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if(d[get<0>(v[x][i])] < y + get<1>(v[x][i])) {
				flag[get<2>(v[x][i])] = true;
				d[get<0>(v[x][i])] = y + get<1>(v[x][i]);
				q.push({ get<0>(v[x][i]),get<1>(v[x][i]) + y });
			}
		}
	}	
	cout << d[e]<<'\n';
	for (int i = 0; i < m; i++)flag[i] = false;
	int counter = 0;
	q.push({ e, d[e] });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < rev[x].size(); i++) {
			if (!flag[get<2>(rev[x][i])]&&d[get<0>(rev[x][i])] == y - get<1>(rev[x][i])) {
				flag[get<2>(rev[x][i])] = true;
				counter++;
				q.push({ get<0>(rev[x][i]) ,y - get<1>(rev[x][i]) });
			}
		}
	}
	cout << counter;
}