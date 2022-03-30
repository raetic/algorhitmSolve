#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n, m;
bool arr[4000001];
int v[4000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m;
	int counter = 0;
	v[0] = 0;
	int vcounter = 1;
	for (int i = 2; i <= m; i++) {
		if (!arr[i]) {
			v[vcounter] = i;
			vcounter++;;
			for (int j = 1; j * i <= m; j++) {
				arr[i * j] = true;

			}
		}
	}
	int res = 0, sum = 0, start = 0, end = 0;
	while (true) {
		if (sum == m)res++;
		if (sum > m)sum -= v[start++];
		else if (end == vcounter)break;
		else sum += v[end++];
}
	cout << res;
}