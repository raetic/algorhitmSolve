	#include<iostream>
	#include<queue>
	#include<utility>
	using namespace std;
	int n;
	int sum;
	int maxn;
	bool flag[10001];
	void dfs(vector <pair<int, int>> v[], int s, int no) {
		if (flag[no])
			return;
		if (s > sum)
		{
			maxn = no;
			sum = s;
		}
		flag[no] = true;
		for (int i = 0; i < v[no].size(); i++) {
			dfs(v, s + v[no][i].second, v[no][i].first);
		}
	}
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
			vector<pair<int, int>> node[10001];
			cin >> n;
			for (int i = 1; i <= n; i++) {
				flag[i] = false;
			}
			for (int i = 0; i < n - 1; i++) {
				int a, b, c;
				cin >> a >> b >> c;
				node[a].push_back(make_pair(b, c));
				node[b].push_back(make_pair(a, c));
			}
			dfs(node, 0, 1);
			for (int i = 1; i <= n; i++) {
				flag[i] = false;
			}
			sum = 0;
			dfs(node, 0, maxn);
			cout << sum << '\n';
	
	}