#include<iostream>
#include<algorithm>
using namespace std;
int n;
int minValue;
int sol;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i == 1)minValue = x;
		else
		minValue = min(x, minValue);
		sol = max(x - minValue, sol);
		cout << sol << ' ';
	}

}