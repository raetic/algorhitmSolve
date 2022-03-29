#include<iostream>
#include<queue>
#include<cmath>
#include<unordered_set>
using namespace std;
int candy[1001][1001];
int dp[1001][1001];
int x, y;
int dpResolve(int a, int b) {
	if (dp[a][b] != -1) {
		return dp[a][b];
}
	int maxi=0;
	if (y > 1) {
		maxi = max(dpResolve(a, b - 1), maxi);
}
	if (x > 1) {
		maxi = max(dpResolve(a - 1, b), maxi);
	}
	if(x>1&&y>1){
		maxi = max(dpResolve(a - 1, b-1), maxi);
	}
	dp[a][b] = maxi+candy[a][b];
	return dp[a][b];
}
int main() {
	cin >> x >> y;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cin >> candy[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dpResolve(x, y);
}