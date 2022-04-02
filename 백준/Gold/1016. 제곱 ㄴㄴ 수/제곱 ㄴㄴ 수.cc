#include <iostream>
#include<vector>
#include<queue>
using namespace std;
bool arr[10000001];
long long n, m;
int main() {	
	cin >> n >> m;

	for (long long i = 2; i <= 1000000; i++) {					
			long long lx = i * i;		
			for (long long j = n / lx; j <= m / lx; j++) {				
				if (j * lx - n < 0)continue;
				arr[j * lx - n] = true;				
		}
	}
	int co = 0;	
	for (int i = 0; i <= m-n ; i++) {
		if (!arr[i]) {
			co++;

		}
	}

	cout << co;
}