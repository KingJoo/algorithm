#include<iostream>
#include<cstdio>
using namespace std;
#define MAX(a,b) (a < b) ? b : a

int res;
int maximum;
int startX, startY;
bool visitCheck[20][20];
bool sameCheck[101];
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
int map[20][20];
int N;

void input() {
	cin >> N;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> map[i][j];
	maximum = (N - 1) * 2;
	return;
}

void dfs(int cnt, int x, int y, int way, int wayCheck_4) {
	if (wayCheck_4 == 4 && x == startX && y == startY) {
		res=MAX(res, cnt);
		return;
	}
	if (wayCheck_4 > 4 || res == maximum || visitCheck[x][y] || sameCheck[map[x][y]])
		return;

	visitCheck[x][y] = true;
	sameCheck[map[x][y]] = true;
	cnt++;

	for (int i = 0;i < 4;i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
		if (way != i)
			dfs(cnt, xx, yy, i, wayCheck_4 + 1);
		else
			dfs(cnt, xx, yy, i, wayCheck_4);
	}

	visitCheck[x][y] = false;
	sameCheck[map[x][y]] = false;

	return;
}

void solve() {
	for (int i = 0;i < N-2;i++) {
		for (int j = 1;j < N-1;j++) {
			startX = i;	startY = j;
			dfs(0, i, j, -1, 0);
			if (res == maximum)	break;
		}
		if (res == maximum)	break;
	}
	return;
}

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		res = -1;
		input();
		solve();
		printf("#%d %d\n", i, res);
	}
	return 0;
}
