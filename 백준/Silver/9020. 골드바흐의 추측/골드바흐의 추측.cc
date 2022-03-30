#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n, m;
bool arr[10001];
int s[10001];
int main() {
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		for (int i = 2; i <= 10000; i++) {
			if (!arr[i]) {
				s[i] = true;
				for (int j = 1; j * i <= 10000; j++) {
					arr[i * j] = true;
				}
			}
		}
		cin >> n;
		int x1, x2;
		for (int i = 1; i <= n / 2; i++) {
			if (s[i] && s[n - i]) {
				x1 = i;
				x2 = n - i;
			}
		}
		cout << x1 << ' ' << x2 << '\n';
	}
}