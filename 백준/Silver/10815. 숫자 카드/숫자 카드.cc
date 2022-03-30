#include <iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long card[500001];
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
}
	sort(card, card + n);
	cin >> m;
	int ans;
	for (int i = 0; i < m; i++) {
		cin >> ans;
		bool isThere=false;
		long long start = 0;
		long long end = n-1;
		while (start <= end) {
			long long mid = (start + end) / 2;
		
			if (ans == card[mid]) {
				isThere = true;
				break;
			}
			if (ans < card[mid]) {
				end = mid - 1;
			}
			if (ans > card[mid]) {
				start = mid + 1;
			}
		}
		if (isThere)cout << 1;
		else cout << 0;
		cout << ' ';
	}
}