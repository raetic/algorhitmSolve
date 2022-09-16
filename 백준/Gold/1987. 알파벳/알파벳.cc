#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
#include<tuple>
using namespace std;
int n, m;
char arr[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int maxDepth;
void DFS(int x, int y, bool check[], int depth) {
	if (depth > maxDepth)maxDepth = depth;
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= m && !check[arr[x2][y2] - 'A']) {
			check[arr[x2][y2] - 'A'] = true;
			DFS(x2, y2, check, depth + 1);
			check[arr[x2][y2] - 'A'] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	bool check[27];
	fill(check,check+27,false);
	check[arr[1][1]-'A'] = true;
	DFS(1, 1, check, 1);
	cout << maxDepth;
}