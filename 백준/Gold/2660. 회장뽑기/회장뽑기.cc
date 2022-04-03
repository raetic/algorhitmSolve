#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int cost[101][101];
int n, m;
int inf = 10000000;
bool flag[101];
vector<int> v;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cost[i][j] = inf;
	}
	int x, y;
	
	cin >> x >> y;
	while (x != -1 || y != -1) {		
		cost[x][y] = 1;
		cost[y][x] = 1;
		cin >> x >> y;
	}
	for (int i = 1; i <= n; i++) {
			cost[i][i] = 0;
		}
	for (int i = 1; i <= n; i++) {		
			for (int j = 1; j <= n; j++) {			
				for (int k = 1; k <= n; k++) {					
					cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
					
				}
			}
			
		}
	int counter = inf;
	int maxi =0;
	for (int i = 1; i <= n; i++) {		maxi = 0;
		for (int j = 1; j <= n; j++) {
		
			if (i == j)continue;
			if (cost[i][j] > maxi) {
				maxi = cost[i][j];	
			}
		}
		
		if (maxi <counter) {
			counter = maxi;
			v.clear();
			v.push_back(i);
		}
		else if (maxi == counter) {
			v.push_back(i);
		}
	}
	cout <<counter << ' ' << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)cout << v[i] << ' ';
}