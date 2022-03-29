#include<iostream>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<string>
using namespace std;
int dp[501][501];
int hc[501];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> hc[i - 1];
		cin >> hc[i];
		dp[i][i] = 0;
	}
	for (int i = 1; i <n; i++) {
		for (int j = 1; j <= n - i; j++) {
			int maxi = 0;
			bool f = false;
			for (int k = j; k < j + i; k++) {
				if (!f) { maxi = dp[j][k] + dp[k + 1][j + i] + hc[j - 1] * hc[k] * hc[j + i]; f = true; }
				else
				maxi = min(maxi, dp[j][k] + dp[k + 1][j + i] + hc[j - 1] * hc[k] * hc[j + i]);
			}
			dp[j][j + i] = maxi;
		}
	}

	cout << dp[1][n];
}