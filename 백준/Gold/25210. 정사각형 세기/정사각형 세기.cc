#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
tuple<int, int, int, int> square[5];
int leftx1, leftx2, rightx1, rightx2, topy1, topy2, boty1, boty2;
long long counter;
void check(int k) { //y=x+k 대각선에 겹치는 점의 갯수 세기
	//1사분면
	long long count1, count2;
	int y1 = min(rightx2 + k,topy1);
	int y2 = max(rightx1 + k,topy2);
	if (y2 > y1)count1 = 0;
	else count1 = y1-y2+1;
	//3사분면
	int y3 = max(leftx1 + k, boty2);
	int y4 = min(leftx2 + k, boty1);
	if (y3 > y4)count2 = 0;
	else count2 = y4-y3+1;
	//cout << y1 << ' ' << y2 << ' ' << y3 << ' ' << y4 << endl;
	counter += count1 * count2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		square[i] = { x1,y1,x2,y2 };
	}
	rightx1 = max(get<0>(square[1]), get<0>(square[4]));
	rightx2 = min(get<2>(square[1]), get<2>(square[4]));
	leftx1 = max(get<2>(square[2]), get<2>(square[3]));
	leftx2 = min(get<0>(square[2]), get<0>(square[3]));
	topy1 = min(get<3>(square[1]), get<3>(square[2]));
	topy2 = max(get<1>(square[1]), get<1>(square[2]));
	boty1 = min(get<1>(square[3]), get<1>(square[4]));
	boty2 = max(get<3>(square[3]), get<3>(square[4]));
	for (int i = -100000; i <= 100000; i++)check(i);
	//check(2);
	cout << counter;
}