#include<iostream>
#include<cstring>
using namespace std;
int aa[16][16], n, nd2, MIN;
bool chk[16];

void sol() {
	int a=0;
	for (int i = 0; i < n-1; i++) {
		if (!chk[i]) {
			for (int j = i+1; j < n; j++) {
				if (!chk[j])
					a += (aa[i][j] + aa[j][i]);
			}
		}
		else{
			for (int j = i+1; j < n; j++) {
				if (chk[j])
					a -= (aa[i][j] + aa[j][i]);
			}
		}
	}
	if (a < 0)	a = -a;
	MIN = a < MIN ? a : MIN;
	return;
}

void dfs(int start, int c) {
	if (c == nd2) {
		sol();
		return;
	}
	if (start == n)	return;
	chk[start] = true;
	dfs(start + 1, c + 1);
	chk[start] = false;
	dfs(start + 1, c);
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//input
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> aa[i][j];
		//init
		MIN = 0x7fffffff;
		nd2 = n >> 1;
		chk[0] = true;
		//solve
		dfs(1,1);
		//output
		cout << '#' << t << ' ' << MIN << '\n';
	}
	return 0;
}
