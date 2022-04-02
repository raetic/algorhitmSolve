#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1001];
int m[1001];
int t;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}m[0] = -10000001;
		int maxi = -10000001;
		for (int i = 1; i <= n; i++) {
			m[i] = max(m[i - 1] + arr[i], arr[i]);
			maxi = max(maxi, m[i]);
		}
		cout << maxi << '\n';
	}
}