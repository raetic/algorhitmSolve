#include<iostream>
#include<string>
using namespace std;
int n, m;
int arr[250001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	int s = 0;
	
	for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 1; i <= m; i++) {
		s += arr[i];
	}
	int ma = s;
	int mcounter = 1;

	for (int i = 1; i <= n - m; i++) {
		s -= arr[i];
		s += arr[i + m];
		if (ma == s) {
			mcounter++;
		}
		if (ma < s) {
			mcounter = 1;
			ma = s;
		}
	}
	if (ma == 0)cout << "SAD" << '\n';
	else cout << ma << '\n' << mcounter;
}
