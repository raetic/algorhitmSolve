#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
long long n, k;
long long find(long long m) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += min(n,(long long)m / i);
		if (i > m) break;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	long long s = 1;
	long long e = n * n;
	long long m = 0;
	while (s <= e) {
		m = (s + e) / 2;
		if (find(m)<k) {
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	cout << e + 1;
}