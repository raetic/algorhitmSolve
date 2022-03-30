#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n, result;
int coin[101];
int dp[100001];
int coi(int a, int b) {
	if (dp[a] != -2) {
		return dp[a];
	}
	int min_ = 100000;
	for (int i = 0; i < b; i++) {
		if (a == coin[i])
		{
			
			dp[a] = 1;
			return 1;
		}
	}
	for (int i = 0; i < b; i++) {
		if(a-coin[i]>0){
			if (coi(a - coin[i], b) > 0 && a - coin[i] > 0) {

				min_ = min(dp[a - coin[i]] + 1, min_);
			}
		}
	}
	if (min_ == 100000) {
		dp[a] = -1;
		return -1;
	}
	else
	{
		dp[a] = min_;
		return min_;
	}
}
int main() {

	scanf("%d", &n);
	scanf("%d",&result);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	
	for (int i = 1; i < result+1; i++) {
		dp[i] = -2;
	}
	int de = coi(result, n);
	printf("%d", de);
}