#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[126][126];
bool flag[126][126];
int b[126][126];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct dxy {
	int d;
		int x;
		int y;
};
struct compare {
	bool operator()(dxy& d1, dxy& d2) {
		return d1.d > d2.d;
	}
};
int n, m;
int main() {
	cin >> n;
	int counter = 0;
	while (n != 0) {
		counter++;
		priority_queue<dxy, vector<dxy>, compare> pq;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				flag[i][j] = false;
				b[i][j] = 10000000;
			}
		}
		b[1][1] = map[1][1];
		pq.push({ map[1][1],1,1 });
		while (!pq.empty()) {
			int d = pq.top().d;
			int x = pq.top().x;
			int y = pq.top().y;
			pq.pop();
			if (flag[x][y])continue;
			flag[x][y] = true;
			for (int i = 0; i < 4; i++) {
				int x2 = x + dx[i];
				int y2 = y + dy[i];
				int di = d + map[x2][y2];
				if (!flag[x2][y2] && di<b[x2][y2]&&x2>0&&y2>0&&x2<=n&&y2<=n) {
					b[x2][y2] = di;
					pq.push({ di,x2,y2 });
				}
			}
		}
		cout <<"Problem "<<counter<<": "<< b[n][n] << '\n';
		cin >> n;
	}
}