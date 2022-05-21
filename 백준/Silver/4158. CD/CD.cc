#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
unordered_set<int> s;
unordered_set<int>::iterator it;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n>>m;
	while (n != 0 && m != 0) {
		s.clear();
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		int counter = 0;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			it = s.find(x);
			if (it != s.end())counter++;
		}
		cout << counter<<'\n';
		cin >> n >> m;
	}
}