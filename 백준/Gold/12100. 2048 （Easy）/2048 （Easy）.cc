#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int n;
int map[21][21];
int maxi;
int counter;
void back(int turn,int type,int m[21][21]) {
	if (turn == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
			
				maxi = max(maxi, m[i][j]);
			}
			
		}
		
		return;
	}
	else {
		int mm[21][21];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				mm[i][j] = m[i][j];
		}
		if (type == 1) { //왼으로 모으기
			for (int i = 1; i <= n; i++) {
				stack<int> s;
				bool merge = false;
				for (int j = 1; j <= n; j++)
				{
					if (mm[i][j] != 0) {
						if (!s.empty() && mm[i][j] == s.top() && !merge) {
							merge = true;
							s.pop();
							s.push(mm[i][j] * 2);
						}
						else {
							merge = false;
							s.push(mm[i][j]); }
					}
					mm[i][j] = 0;
				}
				while (!s.empty()) {
					mm[i][s.size()] = s.top();
					s.pop();
				}
			}
		}
		if (type == 2) { //오른쪽으로 모으기
			for (int i = 1; i <= n; i++) {
				stack<int> s;
				bool merge = false;
				for (int j = n; j >= 1; j--)
				{
					if (mm[i][j] != 0) {
						if (!s.empty() && mm[i][j] == s.top() && !merge) {
							merge = true;
							s.pop();
							s.push(mm[i][j] * 2);
						}
						else { merge = false;
						s.push(mm[i][j]); }
					}
					mm[i][j] = 0;
				}
				while (!s.empty()) {
					mm[i][n + 1 - s.size()] = s.top();
					s.pop();
				}
			}
		}
		if (type == 3) { //위로 모으기
			for (int j = 1; j <= n; j++) {
				stack<int> s;
				bool merge = false;
				for (int i = 1; i <= n; i++)
				{
					if (mm[i][j] != 0) {
						if (!s.empty() && mm[i][j] == s.top() && !merge) {
							merge = true;
							s.pop();
							s.push(mm[i][j] * 2);
						}
						else { merge = false; s.push(mm[i][j]); }
					}
					mm[i][j] = 0;
				}
				while (!s.empty()) {
					mm[s.size()][j] = s.top();
					s.pop();
				}
			}
		}
		if (type == 4) { //아래로 모으기
			for (int j = 1; j <= n; j++) {
				stack<int> s;
				bool merge = false;
				for (int i = n; i >= 1; i--)
				{
					if (mm[i][j] != 0) {
						if (!s.empty() && mm[i][j] == s.top() && !merge) {
							merge = true;
							s.pop();
							s.push(mm[i][j] * 2);
						}
						else { merge = false; s.push(mm[i][j]); }
					}
					mm[i][j] = 0;
				}
				while (!s.empty()) {
					mm[n + 1 - s.size()][j] = s.top();
					s.pop();
				}
			}
		}
		for (int i = 1; i <= 4; i++) {
			back(turn + 1, i, mm);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 4; i++) {
		back(0, i, map);
	}
	cout << maxi;
}