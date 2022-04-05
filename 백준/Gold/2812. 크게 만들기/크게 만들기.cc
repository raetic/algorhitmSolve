#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	string s;
	cin >> s;
	stack<char> st;
	st.push(s[0]);
	int counter = 0;
	int idx = 1;
	 while (idx != n) {		
		 if (counter == m) {
			 st.push(s[idx]);
			 idx++;
			 continue;
		 }
		 if (!st.empty()&&s[idx] > st.top()) {
			 st.pop();	
			// idx++;
			 counter++;
		
		 }
		 else {
			 st.push(s[idx]);
			 idx++;
		 }


		}
	 while (counter != m) {
		 st.pop();
		 counter++;
	 }
	    vector<char> v;
		while (!st.empty()) {
			v.push_back(st.top());
			st.pop();
		}
		for (int i =v.size()-1; i >=0; i--)cout << v[i];
}