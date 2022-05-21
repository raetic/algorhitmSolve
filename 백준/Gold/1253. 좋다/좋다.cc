#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
#include<algorithm>
int arr[2001];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int count = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = n-1;		
		while (start<end) {
			int sum = arr[start]+arr[end];
			if (sum < arr[i])start++;
			else if (sum > arr[i])end--;
			else {
				if (start != i && end != i) {
					count++;
					break;
				}
				else if (start == i)start++;
				else if (end == i)end--;
			}
		}
	}
	cout << count;
}