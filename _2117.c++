#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAX_N 20
#define MAX(a,b) a<b?b:a
int cost[MAX_N * 2];
bool map[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int N, M;
queue<pair<int, int>> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void costInit() {
	int *tmp = new int[(MAX_N * 2)];
	for (int i = 0;i < (MAX_N * 2);i++)
		tmp[i] = i*i;
	for (int i = 1;i < (MAX_N * 2);i++)
		cost[i] = tmp[i] + tmp[i - 1];
	delete[] tmp;
	return;
}

int input() {
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				cnt++;
		}
	return cnt*M;
}

int proc(const int homeNxM) {
	int maxHomeN = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			q.push({ i,j });
			visit[i][j] = true;
			int cnt = 1;
			int size = 1;
			int nextHomeN = 0;
			int homeN = 0;
			if (map[i][j])
				homeN++;
			while (q.size()) {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				size--;
				for (int k = 0;k < 4;k++) {
					int aa = a + dx[k];
					int bb = b + dy[k];
					if (aa < 0 || bb < 0 || aa == N || bb == N || visit[aa][bb])	continue;
					q.push({ aa,bb });
					visit[aa][bb] = true;
					if (map[aa][bb])
						nextHomeN++;
				}
				if (size == 0) {
					if (homeN*M >= cost[cnt])
						maxHomeN = MAX(maxHomeN, homeN);
					homeN += nextHomeN;
					nextHomeN = 0;
					size = q.size();
					cnt++;
					if (homeNxM < cost[cnt]) {
						while (q.size())
							q.pop();
						break;
					}
				}
			}
			for (int i = 0;i < N;i++)
				memset(visit[i], false, sizeof(bool)*N);
		}
	}
    return maxHomeN;
}

int main() {
	costInit();
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++)
		cout << '#' << i << ' ' << proc(input()) << '\n';
	return 0;
}
