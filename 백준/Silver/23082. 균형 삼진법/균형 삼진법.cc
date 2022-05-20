#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int n;
	cin >> n;
	if (n > 0)
		while (n != 0) {
			int p = n % 3;
			n /= 3;
			if (p == 2) {
				n += 1;
				p = -1;
			}
			v.push_back(p);
		}
	else if (n < 0)
		while (n != 0) {
			int p = n % 3;
			n /= 3;
			if (p == -2) {
				n -= 1;
				p = 1;
			}
			v.push_back(p);
		}
	else v.push_back(0);
	for (int i = v.size() - 1; i >= 0; i--) {
		
		if (v[i] != -1)
			cout << v[i];
		else 
			cout << 'T';
		}
}