#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int tc, n, m, cnt, ns[20];
bool sc;
bool cmp(int a, int b) { return a > b; }

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		cnt = 1; memset(ns, 0, sizeof(ns));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> sc;
				if (sc)	ns[i]++;
			}
		}
		sort(ns, ns + n, cmp);
		for (int i = 1; i < n; i++) {
			if (ns[i] == ns[0])	cnt++;
			else break;
		}
		cout << '#' << t << ' ' << cnt << ' ' << ns[0] << '\n';
	}
	return 0;
}
