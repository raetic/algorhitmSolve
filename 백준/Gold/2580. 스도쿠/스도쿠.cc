#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
char no[16];
char d[16];
int map[10][10];
bool Find;
bool flag[82];
vector<pair<int,int>> v;
bool check(int x,int y,int z) {
	for (int i = 1; i <= 9; i++) {
		if (map[i][y] == z)
			return false;
	}
	for (int i = 1; i <= 9; i++) {
		if (map[x][i] == z)
			return false;
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (map[((x - 1) / 3) * 3 + i][((y - 1) / 3) * 3 + j] == z)
				return false;
		}
	}
	return true;
}
void dfs(int x) {
	if (Find) {		
		
		return;
	}
	if (x == v.size()) { Find = true; for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << map[i][j]<<' ';
			}
			cout << endl;
		}return; }
	for (int k = 1; k <= 9; k++) {
		if (check(v[x].first, v[x].second, k))
		{
			map[v[x].first][v[x].second] = k;
			dfs(x + 1);
		}
	}
	map[v[x].first][v[x].second] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)v.push_back({ i,j });
		}
	}
	
	flag[1] = true;
	for (int k = 1; k <= 9; k++) {
		if (check(v[0].first, v[0].second, k))
		{
			map[v[0].first][v[0].second] = k;
			dfs(1);
		}
	}

}