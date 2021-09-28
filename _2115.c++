#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int M[10][10], n, m, c, r;
int rMax[10], tmp[5], tmpSq[5];
bool chk[5];

bool cmp(int a, int b) { return a > b; }

void dfs(int depth, int* sum, int start) {
	if (start==m) {
		int s = 0;
		for (int k = 0; k < m; k++)
			if (chk[k])	s += tmpSq[k];
		*sum = s > *sum ? s : *sum;
		return;
	}
	if (depth + tmp[start] <= c) {
		chk[start] = true;
		dfs(depth + tmp[start], sum, start + 1);
	}
	chk[start] = false;
	dfs(depth, sum, start + 1);
}

int calc(int i, int j) {
	int tSum=0;
	for (int k = 0; k < m; k++) {
		tmp[k] = M[i][j + k];
		tmpSq[k] = tmp[k] * tmp[k];
	}
	memset(chk, 0, sizeof(chk));
	dfs(0,&tSum,0);
	return tSum;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		r = 0;
		memset(rMax, 0, sizeof(rMax));
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> M[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				int RM1 = calc(i, j);
				rMax[i] = rMax[i] > RM1 ? rMax[i] : RM1;
				for (int k = j + m; k + m < n; k++) {
					int RM2 = calc(i, k);
					rMax[i] = rMax[i] > RM2 ? rMax[i] : RM2;
					r = RM1 + RM2 > r ? RM1 + RM2 : r;
				}
			}
		}
		sort(rMax, rMax + n, cmp);
		r = rMax[0] + rMax[1] > r ? rMax[0] + rMax[1] : r;
		cout << '#' << t << ' ' << r << '\n';
	}
	return 0;
}
