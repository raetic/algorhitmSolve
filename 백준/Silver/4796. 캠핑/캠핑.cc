#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
using namespace std;
int n,k,m;
int counter;
int main() {
	cin >> n >> k >> m;
	while (n != 0 || k != 0 || m != 0) {
		counter++;
		cout << "Case " << counter << ": ";
		cout << (m / k) * n + min(n,m%k)<<'\n';
		cin >> n >> k >> m;	
	}
}