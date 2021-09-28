#include<iostream>
using namespace std;
int day, month1, month3, year1, res;
int plan[12], start, iter;

bool input() {
	bool isPlan = false;
	cin >> day >> month1 >> month3 >> year1;
	for (int i = 0;i < 12;i++) {
		cin >> plan[i];
		if (!isPlan && plan[i]) {
			isPlan = true;
			start = i;
		}
	}
	return isPlan;
}

int monthCheck(int a) {
	int cnt = 0;
	for (int i = 0;i < 3;i++) {
		if (a >= 12)	continue;
		if (plan[a] != 0)
			cnt++;
		a++;
	}
	return cnt;
}

int dayCheck(int a) {
	int sum = 0;
	for (int i = 0;i < 3;i++) {
		if (a >= 12)	continue;
		sum += plan[a];
		a++;
	}
	return sum;
}

void dfs(int startM,int breakCnt,int sum) {
	if (breakCnt >= 12|| startM >= 12) {
		if(sum != 0)
			res = res < sum ? res : sum;
		return;
	}
	if (plan[startM] == 0) {
		dfs(startM+1, breakCnt+1, sum);
		return;
	}
	int d_m1 = day * plan[startM];
	int d_m3 = day * dayCheck(startM);
	int m1_3 = month1 * monthCheck(startM);
	int tmp1 = d_m1 < month1 ? d_m1 : month1;
	int tmp2 = d_m3 < m1_3 ? d_m3 : m1_3;
	int tmp3 = tmp2 < month3 ? tmp2 : month3;
	dfs(startM + 1, breakCnt + 1, sum+tmp1);
	dfs(startM + 3, breakCnt + 3, sum+tmp3);
	return;
}

void proc() {
	res = year1;
	iter = start-2;
	if (iter < 0)
		iter = 0;
	for (int i = iter;i <= start;i++)
        dfs(i, 0, 0);
	return;
}

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		if (input())
			proc();
		else
			res = 0;
		cout << '#' << i << ' ' << res << '\n';
	}
	return 0;
}
