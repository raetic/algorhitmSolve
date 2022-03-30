#include <iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n, m;
int arr[1001];
int counter = 0;
void achess() {
	int k = -1; 
	for (int i = 2; i <= m; i++) {
		if (arr[i] != -1&&k==-1)
		{			
			arr[i] = -1;
			counter++;
			if (counter == n) {
				cout << i;
				return;
			}
			k = i;
		}
		else if (arr[i]!=-1&&k != -1 && i % k == 0) {
			counter++;
			if (counter == n) {
				cout << i;
				return;
			}
			
			arr[i] = -1; }
	}
	
	if (k == -1)return;
	else {
		achess(); }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (int i = 2; i <= m; i++)arr[i] = i;
	achess();
	
}