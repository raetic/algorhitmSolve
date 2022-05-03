	#include<iostream>
	#include<queue>
	using namespace std;
	int n, m, money;
	int par[10001];
	bool f[10001];
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void UnionFun(int x,int y) {
		 x = find(x);
		 y = find(y);
		 if (x != y) {
			 if (x < y) {
				 par[y] = x;
			 }
			 else {
				 par[x] = y;
			 }
		 }
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int main() {	
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n >> m >> money;
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			int x;
			cin >> x;;
			pq.push({ x,i });
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			UnionFun(x, y);
		}
		int moneySum = 0;
		for (int i = 1; i <= n; i++)find(i);
		while (!pq.empty()) {		
			int x = pq.top().second;
			int y = pq.top().first;
			pq.pop();
			if (f[par[x]]) { 
				f[x] = true;
				continue; }
			moneySum += y;
			f[x] = true;
			f[par[x]] = true;
		}
		int counter = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i]) { 
				counter++;
			}
		}
		if (counter == n&&moneySum<=money)cout << moneySum;
		else cout << "Oh no";
	}