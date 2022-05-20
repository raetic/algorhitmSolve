#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;

	if (s[0] == 'E')cout << "I";
	else cout << "E";
	if (s[1] == 'S')cout << "N";
	else cout << "S";
	if (s[2] == 'T')cout << "F";
	else cout << "T";
	if (s[3] == 'P')cout << "J";
	else cout << "P";
}