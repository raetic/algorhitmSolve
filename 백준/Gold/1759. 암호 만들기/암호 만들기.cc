#include <iostream>
#include<algorithm>
using namespace std;
int flag[16];
int n,m;
char no[16];
char d[16];
void dfs(int x,int depth) {
	d[depth] = no[x];
	if (depth == n) {
		int counter1 = 0;
		int counter2 = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 'a' || d[i] == 'e' || d[i] == 'i' || d[i] == 'o' || d[i] == 'u') {
				counter1++;
			}
			else counter2++;
		}
		if (counter1 >= 1 && counter2 >= 2) {
			for (int i = 1; i <= n; i++) {
				cout << d[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= m; i++) {
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

	cin >> n>>m;
		
		for (int i = 1; i <= m; i++) {
			cin >> no[i];
		}
		sort(no + 1, no + m+1);
		for (int i = 1; i <= m; i++) {
			
			flag[i] = true;
			dfs(i, 1);
			flag[i] = false;
		}
	
	
}