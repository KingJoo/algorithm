#include<iostream>
using namespace std;
int tc, n, m, money[100], res;
char nn[100][9], mm[9];
bool lucky;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		res = 0;
		for (int i = 0; i < n; i++)
			cin >> nn[i] >> money[i];
		for (int i = 0; i < m; i++) {
			cin >> mm;
			for (int j = 0; j < n; j++) {
				lucky = true;
				for (int k = 0; k < 8; k++) {
					if (nn[j][k] != mm[k]) {
						if (nn[j][k] != '*') {
							lucky = false;
							break;
						}
					}
				}
				if (lucky)	res += money[j];
			}
		}
		cout << '#' << t << ' ' << res << '\n';
	}
	return 0;
}
