#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % n == 0)cout << s[i];
	}
}