#include<iostream>
#include<vector>
using namespace std;
typedef struct {
	int x, y, num, way; //미생물 수, 이동방향
}mic;
#define MAX_N 100
int map[MAX_N][MAX_N];
int N, M, K;
vector<mic> v;

void input() {
	mic tmp;
	cin >> N >> M >> K;
	for (int i = 0;i < K;i++) {
		cin >> tmp.y >> tmp.x >> tmp.num >> tmp.way;
		map[tmp.y][tmp.x]++;
		v.push_back(tmp);
	}
	return;
}

void reset() {
	v.clear();
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			map[i][j] = 0;
	return;
}

bool move(mic * a) {
	map[a->y][a->x]--;
	if (a->way == 1)//상
		a->y--;
	else if (a->way == 2)//하
		a->y++;
	else if (a->way == 3)//좌
		a->x--;
	else//if(a->way==4)//우
		a->x++;
	if (a->x == 0 || a->x == N-1 || a->y == 0 || a->y == N-1) {
		a->num >>= 1;
		if (a->num == 0)
			return false;
		if (a->way == 1)//상
			a->way++;
		else if (a->way == 2)//하
			a->way--;
		else if (a->way == 3)//좌
			a->way++;
		else//if(a->way==4)//우
			a->way--;
	}
	map[a->y][a->x]++;
	return true;
}

int proc() {
	int sum = 0;
	while (M--) {
		for (int i = 0;i < v.size();i++) {
			if (!move(&v.at(i))) {
				v.erase(v.begin() + i);
				i--;
			}
		}
		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				if (map[i][j] > 1) {
					int tmpN = 0;
					int tmpW = 0;
					int tmpNsum = 0;
					int cnt = 0;
					mic tmp;
					for (int k = 0;k < v.size();k++) {
						if (v.at(k).y == i && v.at(k).x == j) {
							tmp.num = v.at(k).num;
							tmpNsum += tmp.num;
							cnt++;
							if (tmpN < tmp.num) {
								tmpW = v.at(k).way;
								tmpN = tmp.num;
							}
							if (cnt == map[i][j]) {
								v.at(k).num = tmpNsum;
								v.at(k).way = tmpW;
                                map[i][j]=1;
								break;
							}
							else {
								v.erase(v.begin() + k);
								k--;
							}
						}
					}
				}
	}
	for (int i = 0;i < v.size();i++)
		sum += v.at(i).num;
	reset();
	return sum;
}

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		input();
		cout << '#' << i << ' ' << proc() << '\n';
	}
	return 0;
}
