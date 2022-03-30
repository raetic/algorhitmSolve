#include <iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long l[10001];
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n >> m;
	long long end = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		end = max(l[i], end);
	}
	long long start = 1;	

	long long mid=0;
	long long ret=0;
	while (start<= end) {
		mid = (start + end) / 2;
		long long count = 0;
		for (int i = 0; i < n; i++) {
			count += l[i] / mid;
		}
		if (count >= m) {		
			start = mid+1;
			ret = max(mid, ret);
		}
		else {			
			end = mid-1;
		}
	}
	cout <<ret;
}