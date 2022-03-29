#include<iostream>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<string>
using namespace std;
int n;
int file[501];
int fileSum[501][501];
int dp[501][501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {	
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> file[i];
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 0;
				fileSum[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				fileSum[i][j] = fileSum[i][j - 1] + file[j];
			}
			dp[i][i] = 0;
		}
		for (int i = 1; i <= n - 1; i++) {
			for (int j = 1; j <= n - i; j++) {
				bool f = false;
				int m = 0;
				for (int k = j; k < j + i; k++) {
					if (!f) {
						f = true;
						m = dp[j][k] + dp[k + 1][j + i] + fileSum[j][j + i];
					}
					else {
						m = min(m, dp[j][k] + dp[k + 1][j + i] + fileSum[j][j + i]);
					}


				}

				dp[j][j + i] = m;
			}

		}
		cout << dp[1][n]<<'\n';
	}
}