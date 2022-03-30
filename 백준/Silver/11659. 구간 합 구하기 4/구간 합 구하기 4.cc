#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int v[100001];
int n, m;
int s[100001];
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	s[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		s[i] = s[i-1] + v[i];

	}
	int r1, r2;
	for (int i = 0; i < m; i++) {
		cin >> r1 >> r2;
		int sum = s[r2] - s[r1-1];
		cout << sum << '\n';
	}

}