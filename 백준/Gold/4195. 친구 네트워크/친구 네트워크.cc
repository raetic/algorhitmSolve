#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string,int> m;
map<string, int>::iterator it;
int n;
string s1,s2;
int counter;
int par[100000];
int chi[100000];
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
int unionFun(int x, int y)
{
	x= find(x);
	y = find(y);
	if (x != y) {
		if (x< y) {
			par[y] = x;
			chi[x] += chi[y];
			return chi[x];
		}
		else {
			par[x] = y;
			chi[y] += chi[x];
			return chi[y];
		}
	}
	else {
		return chi[x];
	}	
}
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			int k1, k2;
			it = m.find(s1);
			if (it != m.end()) {
				k1 = it->second;
			}
			else {
				k1 = counter;
				m.insert({ s1, counter });
				par[counter] = counter;
				chi[counter] = 1;
				counter++;
			}
			it = m.find(s2);
			if (it != m.end()) {	
				k2 = it->second;
			}
			else {
				k2 = counter;
				m.insert({ s2, counter });
				par[counter] = counter;
				chi[counter] = 1;
				counter++;
			}
			cout<<unionFun(k1, k2)<<'\n';
		}
		m.clear();
	}
}