#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int r, c, k;
int rowCount;
int columnCount;
int arr[101][101];
int counter[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	rowCount = 3;
	columnCount = 3;
	int co = 0;
	while (arr[r][c] != k) {		
		co++;
		if (rowCount >= columnCount) {
			int maxColumn = 0;
			for (int i = 1; i <= rowCount; i++) {
				for (int k = 1; k <= 100; k++)counter[k] = 0;
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				for (int j = 1; j <=columnCount; j++) {
					counter[arr[i][j]]++;
				}
				for (int j = 1; j <= 100; j++) {
					if (counter[j] != 0) {
						pq.push({ counter[j],j });
					}
				}			
				int start = 0;		
					for (int j = 1; j <= 100; j++)arr[i][j] = 0;
				
				while (!pq.empty()) {
					int x = pq.top().first;
					int y = pq.top().second;
					pq.pop();
					start++;
					arr[i][start * 2 - 1] = y;
					arr[i][start * 2] = x;
				}
				maxColumn = max(maxColumn, start * 2);
				

			}
			columnCount = maxColumn;
		}
		else {
			int maxRow = 0;
			for (int j = 1; j <= columnCount; j++) {
				for (int i = 1; i <= 100; i++)counter[i] = 0;
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				for (int i = 1; i <= rowCount; i++) {
					counter[arr[i][j]]++;
				}
				for (int i = 1; i <= 100; i++) {
					if (counter[i] != 0) {
						pq.push({ counter[i],i });
					}
				}
			
					for (int k = 1; k <= 100; k++)arr[k][j] = 0;
				
				int start = 0;
				while (!pq.empty()) {
					int x = pq.top().first;
					int y = pq.top().second;
					pq.pop();
					start++;
					arr[start * 2 - 1][j] = y;
					arr[start * 2][j] = x;

				}
				maxRow= max(maxRow, start * 2);
			
				
			}
			rowCount = maxRow;
			}
		
		if (co > 100) {
			co = -1;
			break;
		}
	}
	cout << co;
}