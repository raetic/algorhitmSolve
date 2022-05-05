#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int incounter[501];
vector<int> v[501];
vector<int> outv[501];
bool flag[501];
int arr[501];
int n;
int dp[501];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t,x;
		cin >>t>> x;
		arr[i] = t;
		while (x != -1) {
			incounter[i]++;
			v[x].push_back(i);
			outv[i].push_back(x);
			cin >> x;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (incounter[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front();
		int maxi = 0;
		q.pop();
		for (int i = 0; i < outv[x].size(); i++) {
			maxi = max(maxi, dp[outv[x][i]]);
		}
		dp[x] = maxi + arr[x];
		for (int i = 0; i < v[x].size(); i++) {
			incounter [v[x][i]] --;
			if (incounter[v[x][i]] == 0)q.push(v[x][i]);
		}
	}
	for (int i = 1; i <= n; i++)cout << dp[i] << '\n';
}