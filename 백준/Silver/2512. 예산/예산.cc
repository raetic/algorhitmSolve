#include <iostream>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
long long n,m;
long long money[100001];
long long upper;
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n;
	long long maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		maxi = max(money[i], maxi);
	}
	cin >> m;
	long long start = 0;
	long long end = maxi;
	long long mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < money[i])sum += mid;
			else sum += money[i];
		}
		if (sum <= m) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}cout << end;
}