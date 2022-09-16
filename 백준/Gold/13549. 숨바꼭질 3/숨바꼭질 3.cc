#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
#include<tuple>
using namespace std;
int n, m;
int arriveTime[100001];
bool flag[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,n });	
	while (!pq.empty()) {
		int curPosition = pq.top().second;
		int curTime = pq.top().first;
		pq.pop();
		if (flag[curPosition])continue;
		flag[curPosition] = true;
		arriveTime[curPosition] = curTime;
		if (curPosition == m) {
			cout << curTime;
			return 0;
		}
		if(curPosition+1<=100000)
		pq.push({  curTime + 1 ,curPosition + 1 });
		if(curPosition-1>=0)
		pq.push({  curTime + 1,curPosition - 1 });
		if(curPosition*2<=100000)
		pq.push({  curTime ,curPosition * 2});
	}

}