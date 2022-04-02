#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1025][1025];
int sum[1025][1025];
int sum2[1025][1025];
int n, m,k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m>>k;
	int x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x;
			arr[i][j] = x;
			sum[i][j] = sum[i][j - 1] + x;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum2[i][j] = sum2[i - 1][j] + sum[i][j];
		}
	}
	int s = 0;
	for (int i = 1; i <= k; i++) {
		s = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (sum2[x2][y2] - sum2[x1 - 1][y2] - sum2[x2][y1 - 1] + sum2[x1 - 1][y1 - 1])/((x2-x1+1)*(y2-y1+1)) << '\n';

	}

}