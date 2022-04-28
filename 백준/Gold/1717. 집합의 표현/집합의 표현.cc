#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
int par[1000000];
int find(int v) {
	if (par[v] == v)return v;
	else return par[v]=find(par[v]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		if (x == 0) {
			if (find(y) != find(z)) {
				par[find(y)] = find(z);
			}
		}
		if (x == 1) {
			if (find(y) == find(z)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}