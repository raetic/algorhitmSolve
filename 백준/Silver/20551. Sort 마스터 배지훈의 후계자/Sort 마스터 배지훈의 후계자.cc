#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
int arr[200001];
int ts(int x) {
	int s = 0;
	int e = n;
	bool b=false;
	while (s < e) {
		int mid = (s + e) / 2;
		if (arr[mid] >= x) 
			e = mid;
		else s = mid + 1;		
		if (arr[mid] == x)b = true;
	}
	if (b)return e;
	else return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << ts(x) << '\n';
	}
}