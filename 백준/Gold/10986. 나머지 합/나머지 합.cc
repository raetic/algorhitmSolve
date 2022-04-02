#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long nmg[1001];
long long n, m;
long long co(int i) {
	if (i < 2)return 0;
	long long k=i* (i - 1)/2;
	return k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	long long counter = 0;
	long long x;
	long long sum = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> x;
		sum += x;
		nmg[sum%m]++;
	}
	for (long long i = 0; i <= m; i++) {
		counter += nmg[i] * (nmg[i] - 1) / 2;
	}
	cout << counter+nmg[0];
}