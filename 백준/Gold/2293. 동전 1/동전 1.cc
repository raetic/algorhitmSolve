#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int dp[10001];
int co[101];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> co[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = co[i]; j <= m; j++) {
			dp[j] += dp[j - co[i]];
		}
	}
	cout << dp[m];
}