#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 50
#define MAX_M 50
int tunnel[MAX_N][MAX_M];
bool resArr[MAX_N][MAX_M];
queue<pair<int,int>> q;
int tc, N, M, R, C, L;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void input() {
	cin >> N >> M >> R >> C >> L;
	q.push({ R,C });
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> tunnel[i][j];
	return;
}

int resOutputAndReset() {
	int cnt=0;
	while (q.size()) {
		q.pop();
	}
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++) {
			if (resArr[i][j])
				cnt++;
			resArr[i][j] = false;
		}
	return cnt;
}

int bfs_proc() {
	if (L == 1)
		return 1;

	while (L--) {
		int qSize = q.size();
		while (qSize--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (tunnel[y][x])
				resArr[y][x] = true;
			else
				continue;

			if (tunnel[y][x] == 1)
				for (int i = 0;i < 4;i++) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 0 && (tunnel[yy][xx] == 1||tunnel[yy][xx]==2|| tunnel[yy][xx] == 5|| tunnel[yy][xx] == 6))||
						(i==1&&(tunnel[yy][xx] == 1||tunnel[yy][xx] == 2|| tunnel[yy][xx] == 4|| tunnel[yy][xx] == 7))||
						(i == 2 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 5))||
						(i==3&&(tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3|| tunnel[yy][xx] ==6|| tunnel[yy][xx] ==7 )))
							q.push({ yy,xx });
                }
			else if (tunnel[y][x] == 2)
				for (int i = 0;i < 2;i++) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 0 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 2 || tunnel[yy][xx] == 5 || tunnel[yy][xx] == 6))||
							(i == 1 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 2 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 7)))
                            q.push({ yy,xx });
				}
			else if (tunnel[y][x] == 3)
				for (int i = 2;i < 4;i++) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 2 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 5))||
							(i == 3 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 6 || tunnel[yy][xx] == 7)))
                            q.push({ yy,xx });
				}
			else if (tunnel[y][x] == 4)
				for (int i = 0;i < 4;i = i+3) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 0 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 2 || tunnel[yy][xx] == 5 || tunnel[yy][xx] == 6))||
                            (i == 3 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 6 || tunnel[yy][xx] == 7)))
                            q.push({ yy,xx });
				}
			else if (tunnel[y][x] == 5)
				for (int i = 1;i < 4;i = i+2) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 1 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 2 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 7))||
                            (i == 3 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 6 || tunnel[yy][xx] == 7)))
							q.push({ yy,xx });
				}
			else if (tunnel[y][x] == 6)
				for (int i = 1;i < 3;i++) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 1 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 2 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 7))||
                           (i == 2 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 5)))
							q.push({ yy,xx });
				}
			else if (tunnel[y][x] == 7)
				for (int i = 0;i < 4;i = i + 2) {
					int yy = y + dy[i];
					int xx = x + dx[i];
					if (yy < 0 || xx < 0 || yy == N || xx == M || tunnel[yy][xx] == 0)	continue;
					if (!resArr[yy][xx])
						if ((i == 0 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 2 || tunnel[yy][xx] == 5 || tunnel[yy][xx] == 6))||
                           (i == 2 && (tunnel[yy][xx] == 1 || tunnel[yy][xx] == 3 || tunnel[yy][xx] == 4 || tunnel[yy][xx] == 5)))
							q.push({ yy,xx });
				}
			else
				;
		}
	}
	return resOutputAndReset();
}

int main() {
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		input();
		cout << '#' << i << ' ' << bfs_proc() << '\n';
	}
	return 0;
}
