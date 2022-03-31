#include <iostream>
#include<algorithm>
using namespace std;
int flag[6][6];
bool done[1000001];
int map[6][6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int counter = 0;
int d[6];
void dfs(int x,int y,int depth) {
	d[depth] = map[x][y];
	if (depth == 5) {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum *= 10;
			sum += d[i];
		}
	
		if (!done[sum]) {	
			done[sum] = true;
			counter++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (x2 > 0 && y2 > 0 && x2 <= 5 && y2 <= 5) {
			flag[x2][y2] = true;
			dfs(x2, y2, depth + 1);
			flag[x2][y2] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			flag[i][j] = true;
			dfs(i, j,0);
			flag[i][j] = false;
		}
	}
	cout << counter;
}