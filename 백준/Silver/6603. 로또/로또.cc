#include <iostream>
#include<algorithm>
using namespace std;
int flag[14];
int n;
int no[14];
int d[6];
void dfs(int x,int depth) {
	d[depth] = no[x];
	if (depth == 5) {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			cout << d[i] << ' ';
			
		}
		cout <<'\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]&&x<i) {
			flag[i] = true;
			dfs(i, depth + 1);		
			flag[i] = false;
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	cin >> n;
	while (n != 0) {
		
		for (int i = 1; i <= n; i++) {
			cin >> no[i];
			flag[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			flag[i] = true;
			dfs(i, 0);
		}cout << '\n';
		cin >> n;
	}
}