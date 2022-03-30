#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n, m;
bool arr[10001];
int s[10001];
int main() {
	int d = 1;
	cin >> n >> m;
	for (int i = n; i > n - m; i--) {
		d *= i;
	}
	for (int i = 1; i <= m; i++) {
		d /= i;
	}
	cout << d;
}