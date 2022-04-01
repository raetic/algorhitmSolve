#include <iostream>
#include<algorithm>
using namespace std;
int dpmin[2][3];
int dpmax[2][3];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n;
	dpmin[0][0] = 0;
	dpmin[0][1] = 0;
	dpmin[0][2] = 0;
	dpmax[0][0] = 0;
	dpmax[0][1] = 0;
	dpmax[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		dpmin[0][0] = dpmin[1][0];
		dpmin[0][1] = dpmin[1][1];
		dpmin[0][2] = dpmin[1][2];
		dpmax[0][0] = dpmax[1][0];
		dpmax[0][1] = dpmax[1][1];
		dpmax[0][2] = dpmax[1][2];
		int x, y, z;
		cin >> x >> y >> z;
		dpmin[1][0] = min(dpmin[0][0], dpmin[0][1]) + x;
		dpmax[1][0] = max(dpmax[0][0], dpmax[0][1]) + x;
		dpmin[1][2] = min(dpmin[0][1], dpmin[0][2]) + z;
		dpmax[1][2] = max(dpmax[0][1], dpmax[0][2]) + z;
		dpmin[1][1] = min(min(dpmin[0][0], dpmin[0][1]), dpmin[0][2]) + y;
		dpmax[1][1] = max(max(dpmax[0][0], dpmax[0][1]), dpmax[0][2]) + y;
	}
	cout << max(max(dpmax[1][0], dpmax[1][1]), dpmax[1][2])<<' ';
	cout << min(min(dpmin[1][0], dpmin[1][1]), dpmin[1][2]);
}