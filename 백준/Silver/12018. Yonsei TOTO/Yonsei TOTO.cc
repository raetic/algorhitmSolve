#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
using namespace std;
int n,h,max_mil,s;
int main() {
	priority_queue<int, vector<int>, greater<int>> mil;
	cin >> s >> max_mil;
	for (int j = 0; j < s; j++) {
		cin >> n >> h;			
			priority_queue<int, vector<int>, greater<int>> pq;
			for (int i = 0; i < n; i++) {
				int x;
				cin >> x;
				pq.push(x);
				if (pq.size() > h)pq.pop();
			
		}
			if (n >= h)
				mil.push(pq.top());
			else mil.push(1);
	}
	int sum = 0;
	int counter = 0;
	while (!mil.empty()) {
		
		sum += mil.top();
		mil.pop();
		if (max_mil < sum)break;
		counter++;
	}
	cout << counter;
}