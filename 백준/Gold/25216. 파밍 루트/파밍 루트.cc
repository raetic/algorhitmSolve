#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
int dp[101][5001];
vector<int> v[5001];
vector<int> rv[5001];
tuple<int, int, int, int> monster[5001];
int n, m, ti;
int dpf(int t, int cur,long long def) {	
	if (t == 0) {
		return 0;
	}
	if (get<0>(monster[cur]) + (ti-t) * get<1>(monster[cur]) - get<2>(monster[cur]) * def > 0)
		return 0;
	if (dp[t][cur] != -1)return dp[t][cur];
	int maxi = get<3>(monster[cur]);
	for (int i = 0; i < v[cur].size(); i++) {	
		maxi = max(maxi, dpf(t - 1, v[cur][i],def) + get<3>(monster[cur]));
	}
	dp[t][cur] = maxi;
	return maxi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> ti;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d  ;
		monster[i] = { a,b,c,d };
		for (int j = 1; j <= ti; j++)dp[j][i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		rv[y].push_back(x);
	}
	int maxi = dpf(ti, 1, 2000000000);
	long long s = 0;
	long long e = 2000000000;
	while (s <= e) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= ti; j++)dp[j][i] = -1;
		}
		long long mid = (s + e) / 2;
		if (dpf(ti, 1, mid) == maxi) {			
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << s;
}