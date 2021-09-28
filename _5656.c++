#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;

int m[15][12], c[15][12], cntN[12], N[4], n, w, h, minR, cnt, dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;

void dfs(int depth) {
	if (minR == 0)	return;
	if (depth == n) {
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				c[i][j] = m[i][j];
		memset(cntN, -1, sizeof(cntN));
		int idx = 0;
		while (idx != n) {
			for (int i = 0; i < h; i++) {
				if (c[i][N[idx]] != 0) {
					if (c[i][N[idx]] == 1)	c[i][N[idx]] = 0;
					else	q.push({ i,N[idx] });
					break;
				}
			}
			while (q.size()) {
				int y = q.front().first;
				int x = q.front().second;
				int len = c[y][x] - 1;
				q.pop();
				c[y][x] = 0;
				if (len > 0) {
					len--;
					for (int i = 0; i < 4; i++) {
						int	yy = y + dy[i];
						int xx = x + dx[i];
						if (xx < 0 || yy < 0 || xx >= w || yy >= h)	continue;
						if (c[yy][xx] != 0) {
							if (c[yy][xx] == 1)	c[yy][xx] = 0;
							else q.push({ yy,xx });
						}
						if (len > 0) {
							int yyy = yy;
							int xxx = xx;
							for (int j = 0; j < len; j++) {
								yyy += dy[i];
								xxx += dx[i];
								if (xxx < 0 || yyy < 0 || xxx >= w || yyy >= h)	continue;
								if (c[yyy][xxx] != 0) {
									if (c[yyy][xxx] == 1)	c[yyy][xxx] = 0;
									else q.push({ yyy,xxx });
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < w; i++) {
				if (cntN[i] == 0)	continue;
				cnt = 0;
				for (int j = h - 1; j >= 0; j--) {
					if (c[j][i] != 0) {
						c[h - 1 - cnt][i] = c[j][i];
						if (h - 1 - cnt != j)
							c[j][i] = 0;
						cnt++;
					}
				}
				cntN[i] = cnt;
			}
			idx++;
		}
		cnt = 0;
		for (int i = 0; i < w; i++)
			cnt += cntN[i];
		minR = minR < cnt ? minR : cnt;
		return;
	}
	for (int i = 0; i < w; i++) {
		N[depth] = i;
		dfs(depth + 1);
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		minR = 0x7fffffff;
		scanf("%d %d %d", &n, &w, &h);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &m[i][j]);
		dfs(0);
		printf("#%d %d\n",t,minR);
	}
	return 0;
}
