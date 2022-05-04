#include <iostream>
using namespace std;
int dp[1001][1001];
int n, m;
int dpf(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];
	if (y * 2 > x)return 0;
	dp[x][y] = (dpf(x - 2, y - 1) + dpf(x - 1, y)) % 1000000003;
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = i;
			for (int j = 2; j <= m; j++) {
				dp[i][j] = -1;
			}
	}
	cout << dpf(n, m);
}