#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
#include<tuple>
using namespace std;
int n,m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
char arr[26][26];
pair<int, int> mo;
pair<int, int> z;
pair<int, int> emptyArr;
int counter;
bool flag[26][26];
queue<pair<int, int>> q;
int moEmpty;
int zEmpty;
void CheckRight(int x,int y,bool isMo,bool isCity) {
	y = y + 1;
	if (x > 0 && y > 0 && x <= n && y <= m &&!flag[x][y]) {
		if (arr[x][y] == '.'&&!isCity) {
			if (isMo)moEmpty = 0;
			else zEmpty = 0;
			emptyArr = { x,y };
		
		}
		else if (arr[x][y] != '.') {
			flag[x][y] = true;
			q.push({ x,y });
		}
	}
}
void CheckLeft(int x, int y, bool isMo, bool isCity) {
	y = y - 1;
	if (x > 0 && y > 0 && x <= n && y <= m && !flag[x][y]) {
		if (arr[x][y] == '.' && !isCity) {
			if (isMo)moEmpty = 1;
			else zEmpty = 1;
			emptyArr = { x,y };
			
		}
		else if (arr[x][y] != '.') {
			flag[x][y] = true;
			q.push({ x,y });
		}
	}
}
void CheckUp(int x, int y, bool isMo, bool isCity) {
	x = x - 1;
	if (x > 0 && y > 0 && x <= n && y <= m && !flag[x][y]) {
		if (arr[x][y] == '.' && !isCity) {
			if (isMo)moEmpty = 2;
			else zEmpty = 2;
			emptyArr = { x,y };
	
		}
		else if (arr[x][y] != '.') {
			flag[x][y] = true;
			q.push({ x,y });
		}
	}
}
void CheckDown(int x, int y, bool isMo, bool isCity) {
	x = x + 1;
	if (x > 0 && y > 0 && x <= n && y <= m && !flag[x][y]) {
		if (arr[x][y] == '.' && !isCity) {
			if (isMo)moEmpty = 3;
			else zEmpty = 3;
			emptyArr = { x,y };

		}
		else if (arr[x][y] != '.') {
			flag[x][y] = true;
			q.push({ x,y });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'M')mo = { i,j };
			else if (arr[i][j] == 'Z')z = { i,j };
		}
	flag[mo.first][mo.second] = true;

	q.push({ mo.first,mo.second });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int c = arr[x][y];
		q.pop();
		flag[x][y] = true;
		if (c == 'M') {
			CheckRight(x, y, true, true);
			CheckLeft(x, y, true, true);
			CheckDown(x, y, true, true);
			CheckUp(x, y, true, true);
		}
		else if (c == '+') {
			CheckRight(x, y, true, false);
			CheckLeft(x, y, true, false);
			CheckDown(x, y, true, false);
			CheckUp(x, y, true, false);
		}
		else if (c == '|') {
			CheckDown(x, y, true, false);
			CheckUp(x, y, true, false);
		}
		else if (c == '-') {
			CheckRight(x, y, true, false);
			CheckLeft(x, y, true, false);

		}
		else if (c == '1') {
			CheckRight(x, y, true, false);
			CheckDown(x, y, true, false);
		}
		else if (c == '2') {
			CheckRight(x, y, true, false);

			CheckUp(x, y, true, false);

		}
		else if (c == '3') {

			CheckLeft(x, y, true, false);
			CheckUp(x, y, true, false);

		}
		else if (c == '4') {
			CheckLeft(x, y, true, false);
			CheckDown(x, y, true, false);
		}
	}
	flag[z.first][z.second] = true;
	q.push({ z.first,z.second });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int c = arr[x][y];
		q.pop();
		flag[x][y] = true;
		if (c == 'Z') {
			CheckRight(x, y, false, true);
			CheckLeft(x, y, false, true);
			CheckDown(x, y, false, true);
			CheckUp(x, y, false, true);
		}
		else if (c == '+') {
			CheckRight(x, y, false, false);
			CheckLeft(x, y, false, false);
			CheckDown(x, y, false, false);
			CheckUp(x, y, false, false);
		}
		else if (c == '|') {
			CheckDown(x, y, false, false);
			CheckUp(x, y, false, false);
		}
		else if (c == '-') {
			CheckRight(x, y, false, false);
			CheckLeft(x, y, false, false);

		}
		else if (c == '1') {
			CheckRight(x, y, false, false);
			CheckDown(x, y, false, false);
		}
		else if (c == '2') {
			CheckRight(x, y, false, false);

			CheckUp(x, y, false, false);

		}
		else if (c == '3') {

			CheckLeft(x, y, false, false);
			CheckUp(x, y, false, false);

		}
		else if (c == '4') {
			CheckLeft(x, y, false, false);
			CheckDown(x, y, false, false);
		}
	}
	cout << emptyArr.first << ' ' << emptyArr.second << ' ';
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		int x2 = emptyArr.first + dx[i];
		int y2 = emptyArr.second + dy[i];
		if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= m && arr[x2][y2] != '.' && arr[x2][y2] != 'M' && arr[x2][y2] != 'Z')
			counter++;
	}
	if (counter == 4) {
		cout << '+';
	}
	else {
		if (moEmpty == 0) {
			if (zEmpty == 1) {
				cout << '-';
			}
			else if (zEmpty == 2) {
				cout << 4;
			}
			else if (zEmpty == 3) {
				cout << 3;
			}
		}
		else if (moEmpty == 1) {
			if (zEmpty == 0) {
				cout << '-';
			}
			else if (zEmpty == 2) {
				cout << 1;
			}
			else if (zEmpty == 3) {
				cout << 2;
			}
		}
		else if (moEmpty == 2) {
			if (zEmpty == 1) {
				cout << 1;
			}
			else if (zEmpty == 0) {
				cout << 4;
			}
			else if (zEmpty == 3) {
				cout << '|';
			}
		}
		else if (moEmpty == 3) {
			if (zEmpty == 1) {
				cout << 2;
			}
			else if (zEmpty == 2) {
				cout << '|';
			}
			else if (zEmpty == 0) {
				cout << 3;
			}
		}
	}

}