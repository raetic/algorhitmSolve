#include<iostream>
#include<algorithm>
using namespace std;
string s;
int n;
int result;
bool isSmall(char a) {
	if (a >= 'a')return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	bool curSmall = true;
	bool preDiffer = false;
	result = 1;
	if (!isSmall(s[0])) {
		result = 2;
		preDiffer = true;
	}
	for (int i = 1; i < s.length(); i++) {
		result++;
		if (curSmall) {
			if (isSmall(s[i])) {
				preDiffer = false;
			}
			else {

				if (preDiffer) {
					
					curSmall = false;
					preDiffer = false;
				}
				else {
					result++;
					preDiffer = true;
				}
			}
		}
		else {
			if (!isSmall(s[i])) {
				preDiffer = false;
			}
			else {

				
				if (preDiffer) {
					curSmall = true;
					preDiffer = false;
				}
				else {
					result++;
					preDiffer = true;
				}
			}
		}
	}
	cout << result;
}