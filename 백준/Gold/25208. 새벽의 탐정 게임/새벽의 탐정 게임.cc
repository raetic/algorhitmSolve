#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int dx[4] = { 1,-1,0,0 }; 
int dy[4] = { 0,0,-1,1 }; //아래,위,왼,오
int counter[501][501][6];
int n, m;
char arr[501][501];
int d[2];
int r[2];
bool flag[501][501][6];
int diceState(int dir, int state) { //현재 감옥 위치와,방향에 따라서 바뀌는 감옥 위치를 구하는 함수
	if (dir==0) {
		if (state == 0)return 4;
		if (state == 1)return 5;
		if (state == 2)return 2;
		if (state == 3)return 3;
		if (state == 4)return 1;
		if (state == 5)return 0;
	}
	if (dir == 1) {
		if (state == 0)return 5;
		if (state == 1)return 4;
		if (state == 2)return 2;
		if (state == 3)return 3;
		if (state == 4)return 0;
		if (state == 5)return 1;
	}
	if (dir == 2) {
		if (state == 0)return 2;
		if (state == 1)return 3;
		if (state == 2)return 1;
		if (state == 3)return 0;
		if (state == 4)return 4;
		if (state == 5)return 5;
	}
	if (dir == 3) {
		if (state == 0)return 3;
		if (state == 1)return 2;
		if (state == 2)return 0;
		if (state == 3)return 1;
		if (state == 4)return 4;
		if (state == 5)return 5;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				r[0] = i;
				r[1] = j;
			}
			if (arr[i][j] == 'D') {
				d[0] = i;
				d[1] = j;
			}
		}
	}
	counter[d[0]][d[1]][0] = 0;
	flag[d[0]][d[1]][0] = true;
	queue<tuple<int, int, int>> q;
	q.push({d[0], d[1], 0});
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int state = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			int state2 = diceState(i, state);			
			if (x2<1|| y2<1 ||x2>n|| y2>m ||flag[x2][y2][state2]||arr[x2][y2]=='#')continue;
			if (x2 == r[0] && y2 == r[1]) {
				if (state2 != 0)continue;
				else {
					cout << counter[x][y][state] + 1;
					return 0;
				}
			}
			else {
				flag[x2][y2][state2] = true;
				counter[x2][y2][state2] = counter[x][y][state] + 1;
				q.push({ x2,y2,state2 });
			}
		}
	}
	cout << -1;
}