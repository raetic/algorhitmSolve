#include<iostream>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int n,m;
int t[1001];
int dp[1001];
vector<int> v[1001];
int dpf(int d) {
	if (dp[d] != -1)return dp[d];
	int maxint = 0;
	for (int i = 0; i < v[d].size(); i++) {
		maxint = max(dpf(v[d][i]), maxint);
	}
	dp[d] = maxint + t[d];
	return dp[d];
}
int main() {
	ios::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int c = 0; c < test; c++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) { cin >> t[i]; 
		dp[i] = -1; 
		v[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v[y].push_back(x);
		}
		cin >> m;
		cout << dpf(m)<<'\n';
	}
}