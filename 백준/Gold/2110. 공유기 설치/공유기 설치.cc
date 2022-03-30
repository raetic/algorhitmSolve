#include <iostream>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
long long n,m;
long long house[200001];
long long upper;
int houseF(int d) {
	int startX = house[1]+d;
	int x = 1;
	for (int i = 1; i <= n; i++) {
		if (house[i] >= startX) {	
			x++;	
			if (x == m)return house[i];
			startX = house[i] + d;		
		}
		
	}
	while (x == m) {
		x++;
		startX += d;
	}
	return startX;
}
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> house[i];
	}
	sort(house+1, house + n+1);
	long long mid, start, end;
	start = 1;//0으로 해도 무방하나 ??잘 모르겠군
	end = house[n - 1]-house[0];
	while (start <= end) {
		mid = (start + end) / 2;
		int final = houseF(mid);
		if (final > house[n]) {
			end = mid - 1;
		}		
		else {
			start = mid + 1;
		}


	}

	cout <<end;

}