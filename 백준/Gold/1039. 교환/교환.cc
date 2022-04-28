#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
string maxs="-1";
bool flag[10000000][11];
string swap(string s2,int a, int b) {
	if (s2.length() == 1)return "-1";
	char c1 = s2[a];
	char c2 = s2[b];
	s2[a] = c2;
	s2[b] = c1;
	if (s2[0] == '0')return "-1";
	return s2;
}
int main() {
	string s;
	cin >> s >> n;
	int sLength = s.length();
	queue<pair<string,int>> q;
	q.push({ s,0 });
	while (!q.empty())
	{
		string s2 = q.front().first;
		int k = q.front().second;
		if (k == n) {
			maxs = max(s2, maxs);
		}
		q.pop();
		for (int i = 0; i < sLength-1; i++) {
			for (int j = i + 1; j < sLength; j++) {
				string s3=swap(s2, i, j);	
				if (s3 != "-1"&&k<n&&!flag[stoi(s3)][k+1]) {
					flag[stoi(s3)][k+1] = true;
					q.push({ s3,k + 1 });
				}
			}
		}
	}	
	cout << maxs;
}