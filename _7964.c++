#include<iostream>
using namespace std;
int tc, n, d, s, cnt;
bool ct;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cnt = 0;
		cin >> n >> d;
		cin >> ct;
		if (!ct)	cnt++;
		s = 0;
		for (int i = 1; i < n-1; i++) {
			cin >> ct;
			if (ct)
				s = i;
			else
				if (s + d == i) {
					cnt++;
					s = i;
				}
		}
		cin >> ct;
		if (!ct)	cnt++;
		cout << '#' << t << ' ' << cnt << '\n';
	}
	return 0;
}
