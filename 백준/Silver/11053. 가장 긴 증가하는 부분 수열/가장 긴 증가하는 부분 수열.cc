#include<iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
