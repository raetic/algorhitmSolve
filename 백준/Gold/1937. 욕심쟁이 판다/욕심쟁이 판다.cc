#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int arr[501][501];
int dp[501][501];
int dpf(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];
	int m = 0;
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && arr[x2][y2] < arr[x][y]) {
			m = max(dpf(x2, y2) + 1, m);
		}
	}
	dp[x][y] = m;
	return m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int m=0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) { 
		dp[i][j] = -1;
		cin >> arr[i][j]; }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			m=max(m,dpf(i, j));
		}
	
	cout << m+1;
}