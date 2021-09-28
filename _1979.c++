#include<iostream>
using namespace std;

int main() {
	int tc, n, k, len, cnt;
	bool map[15][15];
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n >> k;
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)
				cin >> map[a][b];
		cnt = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (map[a][b]) {
					if ((a==0)||(a - 1 >= 0 && !map[a - 1][b])) {
						len = 0;
						for (int c = 0; c < n; c++) {
							if ((a + c) < n && map[a + c][b])
								len++;
							else
								break;
						}
						if (len == k)
							cnt++;
					}
					if ((b==0)||(b - 1 >= 0 && !map[a][b - 1])) {
						len = 0;
						for (int c = 0; c < n; c++) {
							if ((b + c) < n && map[a][b + c])
								len++;
							else
								break;
						}
						if (len == k)
							cnt++;
					}
				}
			}
		}
		cout << '#' << i << ' ' << cnt << endl;
	}
	return 0;
}
