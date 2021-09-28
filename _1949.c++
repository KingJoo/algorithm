#include<iostream>
#include<queue> // --> queue, pair // #include<utility> --> pair
#include<cstring> // --> memset()
using namespace std;

//default
#define MAX_NUM 8
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};

//init unit
int map[MAX_NUM][MAX_NUM]; //reset()으로 case마다 초기화
int heightest; //heightest point
int max_route; //output val
queue<pair<int, int>> q; //heigh point
bool visit[MAX_NUM][MAX_NUM];

//input
int tc, N, K, dat;

void input() {
	cin >> N >> K;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> dat;
			heightest = (heightest < dat) ? dat : heightest;
			map[i][j] = dat;
		}
	return;
}

void dfs(int a,int b,int cnt, bool useK) {
	visit[a][b] = true;//방문 표시
	cnt++;//방문 길이 늘리기

	for (int i = 0;i < 4;i++) {
		int xx = a + x[i];
		int yy = b + y[i];
		if (xx < 0 || yy < 0 || xx >= N || yy >= N || visit[xx][yy])	continue;
		//다음 방문할 곳이 낮으면 방문!
		if (map[xx][yy] < map[a][b]){
			dfs(xx,yy,cnt, useK);
		}
		//다음 방문할 곳이 같은 높이거나 높으면 1부터 K만큼 깎아서 방문해 봄, 단 한번이라도 깎았으면 더 못 깎음
		else { //if (map[xx][yy] = map[a][b]){
			if (!useK) {
				for (int j = 1;j <= K;j++) {
					map[xx][yy] -= j;
					useK = true;
					if (map[xx][yy] < map[a][b])
						dfs(xx,yy,cnt, useK);
					map[xx][yy] += j;
					useK = false;
				}
			}
		}
	}
	max_route = (max_route < cnt) ? cnt : max_route;
	/*
	cout << "visit";
	for (int i = 0;i < N;i++) {
		cout << '\n';
		for (int j = 0;j < N;j++)
			cout << visit[i][j];
	}
	cout << "cnt = " << cnt << '\n';
	cout << "-----------------------------------\n";
	*/
	visit[a][b] = false; //방문 표시 제거
	cnt--;//방문 길이 줄이기
	return;
}

void bfs_proc(int N) {
	//q에 최고점 좌표 넣기
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			if (map[i][j] == heightest)
				q.push({ i,j });
	//bfs
	while (q.size()) {
		dfs(q.front().first, q.front().second, 0, false);
		q.pop();
	}
	return;
}

void reset(int N) {
	//map[][] reset
	for (int i = 0;i < N;i++)
		memset(&map[i], 0, sizeof(int)*N);

	//max_route val reset
	max_route = 0;

	//heightest val reset
	heightest = 0;

	//q reset
	while (q.size()) {
		q.pop();
	}

	//visit[][] reset
	for (int i = 0;i < N;i++)
		memset(&visit[i],false,sizeof(bool)*N);

	return;
}

int main() {
	cin >> tc;
	tc++;

	int * tcArr = new int[tc];

	for (int i = 1;i < tc;i++) {
		input();
		bfs_proc(N);
		tcArr[i] = max_route;
		reset(N);
	}

	//output
	for (int i = 1;i < tc;i++)
		cout << "#" << i << ' ' << tcArr[i] << '\n';

	delete[] tcArr;
	//break point
	//cin >> tc;
	return 0;
}
