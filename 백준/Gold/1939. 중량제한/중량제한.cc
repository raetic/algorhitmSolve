#include <iostream>
#include<algorithm>
#include<queue>
#include<climits>
#include<vector>
using namespace std;
long long n,m;
vector<pair<long long,long long>> v[10001];
vector<pair<long long,long long>> w[10001];
bool flag[10001];
int s, e;
bool canGo(int w) {
	for (int i = 1; i <= n; i++)flag[i] = false;
	queue<long long> q;
	q.push(s);
	flag[s] = true;
	while (!q.empty()) {
		if (q.front() == e)return true;
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (!flag[v[x][i].first] && w <= v[x][i].second) {
				flag[v[x][i].first] = true;
				q.push(v[x][i].first);
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		long long x, y,z;
		cin >> x >> y>>z;	
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	long long start = 0;
	long long end = INT_MAX;
	long long mid=0;
	cin >> s >> e;
	while (start <= end) {
		mid = (start + end) / 2;
		if (canGo(mid)) {
		start = mid + 1;
		}
		else {
			end=mid-1;
		}
	}
	cout <<end;
}