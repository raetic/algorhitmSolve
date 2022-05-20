#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> up;
priority_queue<long long> down;
int n;
int mid;
void make(long long k) {
	if (up.size() == down.size())down.push(k);
	else up.push(k);
	if (!up.empty() && !down.empty()) {
		if (up.top() < down.top()) {
			int a = up.top();
			int b = down.top();
			up.push(b);
			down.push(a);
			up.pop();
			down.pop();
		}
	}
	mid = down.top();
}
int main(){
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cin >> n;
	long long x,k;
	long long premid=0;
	long long predis = 0;
	long long dis = 0;
	for (int i = 0; i < n; i++) {

		long long ysum = 0;
		int s1 = up.size();
		int s2 = down.size();
		cin >> x >> k;
		
		make(k);
		dis +=abs(premid - mid) * abs(s1-s2) + abs(mid - k) + abs(x);
		cout << mid << ' '<<dis<<'\n';
		premid = mid;
	}

}