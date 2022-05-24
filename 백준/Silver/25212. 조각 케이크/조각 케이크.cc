#include<iostream>
#include<algorithm>
using namespace std;
int n;
int result;
double arr[10];
bool flag[10];
void find(double sum, int val) {
	if (sum > 1.01)return;
	else if (sum >= 0.99) {
		result++;
		return;
	}
	for (int i = val+1; i < n; i++) {
		if (!flag[i]) {
			flag[i] = true;
			find(sum +  1/ arr[i]  , i);
			flag[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++) {
		flag[i] = true;
		find(1 / arr[i], i);
	}
	cout << result;
}