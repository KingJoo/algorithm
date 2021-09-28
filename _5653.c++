#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int grid[350][350],n,m,k,dqSize;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
enum { NA=0, A};//status

typedef struct {
	int y, x, life, status, time;
}S;

deque<S> dq;

bool comp(S s1, S s2) {
	return s1.life > s2.life;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//init
		for (int i = 0; i < 350; i++) {
			for (int j = 0; j < 350; j++) {
				grid[i][j] = 0;
			}
		}
		dq.clear();
		//input
		cin >> n >> m >> k;
		for (int i = 150; i < 150 + n; i++) {
			for (int j = 150; j < 150 + m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] != 0)
					dq.push_back({i,j,grid[i][j],NA,grid[i][j]});
			}
		}
		//solve
		while (k--) {
			dqSize = dq.size();
			sort(dq.begin(), dq.end(), comp);
			while (dqSize--) {
				dq.front().time--;//시간줄이기
				if (dq.front().status == A && dq.front().time == dq.front().life - 1) {//번식하기
					int x = dq.front().x;
					int y = dq.front().y;
					int life = dq.front().life;
					for (int i = 0; i < 4; i++) {
						int xx = x + dx[i];
						int yy = y + dy[i];
						if (xx < 0 || yy < 0 || xx == 350 || yy == 350)	continue;
						if (grid[yy][xx] == 0) {
							dq.push_back({ yy, xx, life, NA, life });
							grid[yy][xx] = life;
						}
					}
					if (dq.front().time > 0)
						dq.push_back(dq.front());
					dq.pop_front();
				}
				else {
					if (dq.front().time == 0) {//시간 0일때
						if (dq.front().status == NA) {//비활->활
							dq.front().status++;
							dq.front().time = dq.front().life;
							dq.push_back(dq.front());
							dq.pop_front();
						}
						else {//활->죽
							dq.pop_front();
						}
					}
					else {//시간 0아닐때
						dq.push_back(dq.front());
						dq.pop_front();
					}
				}
			}
		}
		//output
		cout << '#' << t << ' ' << dq.size() << '\n';
	}
	return 0;
}
