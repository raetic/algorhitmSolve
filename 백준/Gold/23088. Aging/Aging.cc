#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<tuple>
using namespace std;
int n;
struct job
{
	int start;
	int pri;
	int end;
	int no;
};
struct compare
{
	bool operator()(job& j1, job& j2) {
		
		return j1.start > j2.start;
	}
};
struct compare2 {
	bool operator()(job& j1, job& j2) {
		if (j1.pri == j2.pri && j1.end == j2.end)
			return j1.no > j2.no;
		else if (j1.pri == j2.pri)
			return j1.end > j2.end;
		else return j1.pri < j2.pri;

	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	priority_queue<job,vector<job>,compare> pq;
	priority_queue<job, vector<job>, compare2> pq2;
	queue<int> doneq;
   
	int exT = 0;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;	
			pq.push({ x,y- x,z,i});
		
	}
	int curTime=pq.top().start;
	int counter = 0;
	while (counter!=n) {		
			while (!pq.empty()&&pq.top().start <= curTime) {
			
				pq2.push(pq.top());
				pq.pop();			
		}
		
		if (!pq2.empty()) {		
			curTime += pq2.top().end;
			cout << pq2.top().no<<' ';
			pq2.pop();		
			counter++;
		}
	
	}

}