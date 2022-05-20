#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<tuple>
using namespace std;
vector<pair<int, int>> v[100001];
bool flag[100001];
int n, m, k;
bool pass[200001];
int team[100001];
vector<int> p;
bool f;
bool find(int key) {
	for (int i = 1; i <= m; i++) {
		pass[i] = false;
	}
	for (int i = 0; i <= key; i++) {
		pass[p[i]] = true;
	}
	for (int i = 1; i <= n; i++)flag[i] = false;
	queue<int> q;
	q.push(1);
	flag[1] = true;
	team[1] = 1;
	while (!q.empty()) {
		int h = q.front();
		q.pop();
		for (int j = 0; j < v[h].size(); j++) {
			if (pass[v[h][j].second]) { continue; }
			if (flag[v[h][j].first] && team[v[h][j].first] == team[h]) {
				return false;
			}
			if (!flag[v[h][j].first]) {
				team[v[h][j].first] = team[h] * -1;
				flag[v[h][j].first] = true;
				q.push(v[h][j].first);
			}
		}
	}
	f = true;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int passcount = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back({ y,i });
		v[y].push_back({ x,i });
	}

	p.push_back(0);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		p.push_back(x);
	}
	int s = 0;
	int e = k;
	while (s <= e) {
		int mid = (s + e) / 2;
		bool k = find(mid);
		if (k) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	find(s);
	if (!f)cout << -1;
	else {
		int counter1 = 0;
		int counter2 = 0;
		cout << s << '\n';
		for (int i = 1; i <= n; i++) {
			if (team[i] == 1)counter1++;
			if (team[i] == -1)counter2++;
		}
		int ma = max(counter1, counter2);
		int mi = min(counter1, counter2);
		cout << mi << ' ' << ma;
	}

}