#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int dp[1001][1001];
bool arr[1001][1001];
int n, m,q;
int dpf(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];
	int sum = 0;
	if (y % 2 == 1) {
		if (x - 1 > 0 && y > 0 && x - 1 <= n && y <= m && !arr[x - 1][y])
		{
			sum += dpf(x - 1, y);
		}
		if (x - 1 > 0 && y - 1 > 0 && x - 1 <= n && y - 1 <= m && !arr[x - 1][y - 1])
		{
			sum += dpf(x - 1, y - 1);
			sum %= 1000000007;
		}
		if (x > 0 && y - 1 > 0 && x <= n && y - 1 <= m && !arr[x][y - 1])
		{
			sum += dpf(x, y - 1);
			sum %= 1000000007;
		}

	}
	else {
		
		if (x - 1 > 0 && y > 0 && x - 1 <= n && y <= m && !arr[x - 1][y])
		{
			sum += dpf(x - 1, y);
			sum %= 1000000007;
		}
		if (x > 0 && y - 1 > 0 && x <= n && y - 1 <= m && !arr[x][y - 1])
		{
			sum += dpf(x, y - 1);
			sum %= 1000000007;
		}
		if (x + 1 > 0 && y - 1 > 0 && x + 1 <= n && y - 1 <= m && !arr[x + 1][y - 1])
		{
			sum += dpf(x + 1, y - 1);
			sum %= 1000000007;
		}
	}
	dp[x][y] = sum;
	return dp[x][y];
}
int main() {
	cin >> n >> m>>q;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			dp[i][j] = -1;
	}
	dp[1][1] = 1;
	cout << dpf(n, m);
}