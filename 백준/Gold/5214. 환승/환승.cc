#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int n, k, m;
int con[1001][1001];
bool flag[100001];
int set[1001];
int counter[100001];
bool flag2[1000];
vector<int> station[100001];
int main() {
    int cnt = 1;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> con[i][j];
            station[con[i][j]].push_back(i);
        }
    }
    queue<int> q;
    q.push(1);
    flag[1] = true;
    counter[1] = 1;
    while (!q.empty()) {
        int x = q.front();      
        q.pop();
        vector<int> v;
        for (int i = 0; i < station[x].size(); i++) {
            for (int j = 1; j <= k; j++) {
                if (x == con[station[x][i]][j]) {
                    v.push_back(station[x][i]);
                    flag2[station[x][i]] = true;
                    break;
                }
            }
       }
        for (int i = 0; i < v.size(); i++) {
            for (int j = 1; j <= k; j++) {
                if (!flag[con[v[i]][j]]) {
                    flag[con[v[i]][j]] = true;
                    counter[con[v[i]][j]] = counter[x] + 1;                  
                    q.push(con[v[i]][j]);
                }
            }
        }
    }
    if (counter[n] == 0)cout << -1;
    else
        cout << counter[n];
}