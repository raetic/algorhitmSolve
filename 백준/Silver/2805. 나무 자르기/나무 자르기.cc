#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long n, m;
	long long tree[1000000];
	long long counter = 0;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	long long start = 0;
	
	long long mid;
	long long answer;
	sort(tree, tree + n);
	long long end = tree[n - 1];
	while(start<=end) {
		mid = (start + end) / 2;		
		int p;
		for (int i = 0; i < n; i++)
		{
			p=tree[i] - mid;
			if (p < 0)p = 0;
			counter = counter + p;
		}
		if (counter == m)
		{
			answer = mid;
			break;
		}
		if (counter < m)
		{
			end = mid - 1;
		}
		if (counter > m) {
			answer = mid;
			start = mid + 1;
		}
		counter = 0;
	}

	cout <<answer << endl;	
}