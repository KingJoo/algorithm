#include<iostream>
using namespace std;
#define D_MAX 13
#define W_MAX 20
#define MIN(a,b) (a<b)?a:b
bool film[D_MAX][W_MAX];
int D, W, K, res;

void input() {
	cin >> D >> W >> K;
	for (int i = 0;i < D;i++)
		for (int j = 0;j < W;j++)
			cin >> film[i][j];
	return;
}

bool shockTestPass() {
	for (int i = 0;i < W;i++) {
		bool before = film[0][i];
		int cnt = 1;
		for (int j = 1;j < D;j++) {
			if (before == film[j][i])
				cnt++;
			else {
				before = film[j][i];
				cnt = 1;
			}
			if (cnt >= K)
				break;
		}
		if (cnt < K)
			return false;
	}
	return true;
}

void inject(int depth, bool AorB) {
	for (int i = 0;i < W;i++)
		film[depth][i] = AorB;
	return;
}

void Recovery(int depth, bool * chkRecovery) {
	for (int i = 0;i < W;i++)
		film[depth][i] = chkRecovery[i];
	return;
}

void dfs(int d, int injection) {
	bool recovery[W_MAX] = {false,};
	for (int i = 0;i < W;i++)
		recovery[i] = film[d][i];

	injection++;
	for (int i = 0;i < 2;i++) {
		inject(d, i);
		if (shockTestPass())
            res = MIN(injection, res);
		else {
			for (int j = d + 1;j < D;j++)
				if (injection < res - 1)
                    dfs(j, injection);
		}
	}
	Recovery(d, recovery);
	return;
}

void proc() {
	if (shockTestPass()) {
		res = 0;
		return;
	}

	for (int i = 0;i < D;i++)
		dfs(i, 0);
	return;
}

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		input();
		if (K != 1) {
			res = K;
			proc();
		}
		else
			res = 0;
		cout << '#' << i << ' ' << res << '\n';
	}
	return 0;
}
