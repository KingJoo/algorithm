#include<iostream>
#include<cstring>
using namespace std;
typedef struct { int y; int x; }Point;
int map[100][100], m, n, sY, sX;
Point wH[5][2];
bool whChk[5];
enum { UP = 0, DOWN, LEFT, RIGHT };
//상하좌우 0123

void init() {
	m = 0;
	memset(whChk, 0, sizeof(whChk));
	return;
}

void dfs(int y, int x, int way, int cnt) {
	int nextY, nextX;
	if (way == UP) {
		nextY = y - 1;
		nextX = x;

		if (nextY == -1) {
			dfs(nextY, nextX, DOWN, cnt + 1);
			return;
		}
		else {
			if ((nextY == sY && nextX == sX) || map[nextY][nextX] == -1) {
				//cout << "1 "<< cnt << endl;
				m = cnt > m ? cnt : m;
				return;
			}
			else if (map[nextY][nextX] == 1)
				dfs(nextY, nextX, DOWN, cnt + 1);
			else if (map[nextY][nextX] == 2)
				dfs(nextY, nextX, RIGHT, cnt + 1);
			else if (map[nextY][nextX] == 3)
				dfs(nextY, nextX, LEFT, cnt + 1);
			else if (map[nextY][nextX] == 4)
				dfs(nextY, nextX, DOWN, cnt + 1);
			else if (map[nextY][nextX] == 5)
				dfs(nextY, nextX, DOWN, cnt + 1);
			else if (map[nextY][nextX] == 0)
				dfs(nextY, nextX, way, cnt);
			else {
				if (wH[map[nextY][nextX] - 6][0].y == nextY && wH[map[nextY][nextX] - 6][0].x == nextX)
					dfs(wH[map[nextY][nextX] - 6][1].y, wH[map[nextY][nextX] - 6][1].x, way, cnt);
				else
					dfs(wH[map[nextY][nextX] - 6][0].y, wH[map[nextY][nextX] - 6][0].x, way, cnt);
			}
		}
	}
	else if (way == DOWN) {
		nextY = y + 1;
		nextX = x;

		if (nextY == n) {
			dfs(nextY, nextX, UP, cnt + 1);
			return;
		}
		else {
			if ((nextY == sY && nextX == sX) || map[nextY][nextX] == -1) {
				//cout << "2 " << cnt << endl;
				m = cnt > m ? cnt : m;
				return;
			}
			else if (map[nextY][nextX] == 1)
				dfs(nextY, nextX, RIGHT, cnt + 1);
			else if (map[nextY][nextX] == 2)
				dfs(nextY, nextX, UP, cnt + 1);
			else if (map[nextY][nextX] == 3)
				dfs(nextY, nextX, UP, cnt + 1);
			else if (map[nextY][nextX] == 4)
				dfs(nextY, nextX, LEFT, cnt + 1);
			else if (map[nextY][nextX] == 5)
				dfs(nextY, nextX, UP, cnt + 1);
			else if (map[nextY][nextX] == 0)
				dfs(nextY, nextX, way, cnt);
			else {
				if (wH[map[nextY][nextX] - 6][0].y == nextY && wH[map[nextY][nextX] - 6][0].x == nextX)
					dfs(wH[map[nextY][nextX] - 6][1].y, wH[map[nextY][nextX] - 6][1].x, way, cnt);
				else
					dfs(wH[map[nextY][nextX] - 6][0].y, wH[map[nextY][nextX] - 6][0].x, way, cnt);
			}
		}
	}
	else if (way == LEFT) {
		nextY = y;
		nextX = x - 1;

		if (nextX == -1) {
			dfs(nextY, nextX, RIGHT, cnt + 1);
			return;
		}
		else {
			if ((nextY == sY && nextX == sX) || map[nextY][nextX] == -1) {
				//cout << "3 " << cnt << endl;
				m = cnt > m ? cnt : m;
				return;
			}
			else if (map[nextY][nextX] == 1)
				dfs(nextY, nextX, UP, cnt + 1);
			else if (map[nextY][nextX] == 2)
				dfs(nextY, nextX, DOWN, cnt + 1);
			else if (map[nextY][nextX] == 3)
				dfs(nextY, nextX, RIGHT, cnt + 1);
			else if (map[nextY][nextX] == 4)
				dfs(nextY, nextX, RIGHT, cnt + 1);
			else if (map[nextY][nextX] == 5)
				dfs(nextY, nextX, RIGHT, cnt + 1);
			else if (map[nextY][nextX] == 0)
				dfs(nextY, nextX, way, cnt);
			else {
				if (wH[map[nextY][nextX] - 6][0].y == nextY && wH[map[nextY][nextX] - 6][0].x == nextX)
					dfs(wH[map[nextY][nextX] - 6][1].y, wH[map[nextY][nextX] - 6][1].x, way, cnt);
				else
					dfs(wH[map[nextY][nextX] - 6][0].y, wH[map[nextY][nextX] - 6][0].x, way, cnt);
			}
		}
	}
	else {
		nextY = y;
		nextX = x + 1;

		if (nextX == n) {
			dfs(nextY, nextX, LEFT, cnt + 1);
			return;
		}
		else {
			if ((nextY == sY && nextX == sX) || map[nextY][nextX] == -1) {
				//cout << "4 " << cnt << endl;
				m = cnt > m ? cnt : m;
				return;
			}
			else if (map[nextY][nextX] == 1)
				dfs(nextY, nextX, LEFT, cnt + 1);
			else if (map[nextY][nextX] == 2)
				dfs(nextY, nextX, LEFT, cnt + 1);
			else if (map[nextY][nextX] == 3)
				dfs(nextY, nextX, DOWN, cnt + 1);
			else if (map[nextY][nextX] == 4)
				dfs(nextY, nextX, UP, cnt + 1);
			else if (map[nextY][nextX] == 5)
				dfs(nextY, nextX, LEFT, cnt + 1);
			else if (map[nextY][nextX] == 0)
				dfs(nextY, nextX, way, cnt);
			else {
				if (wH[map[nextY][nextX] - 6][0].y == nextY && wH[map[nextY][nextX] - 6][0].x == nextX)
					dfs(wH[map[nextY][nextX] - 6][1].y, wH[map[nextY][nextX] - 6][1].x, way, cnt);
				else
					dfs(wH[map[nextY][nextX] - 6][0].y, wH[map[nextY][nextX] - 6][0].x, way, cnt);
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n;
		init();
		//input
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> map[j][k];
				if (map[j][k] >= 6) {
					if (!whChk[map[j][k] - 6]) {
						wH[map[j][k] - 6][0].y = j;
						wH[map[j][k] - 6][0].x = k;
						whChk[map[j][k] - 6] = true;
					}
					else {
						wH[map[j][k] - 6][1].y = j;
						wH[map[j][k] - 6][1].x = k;
					}
				}
			}
		}
		//solve
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				sY = j; sX = k;
				if (map[j][k] == 0) {
					for (int l = 0; l < 4; l++) {
						dfs(j, k, l, 0);
					}
				}
			}
		}
		//output
		cout << '#' << i << ' ' << m << endl;
	}
	return 0;
}
