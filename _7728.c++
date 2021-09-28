#include<iostream>
#include<cstring>
using namespace std;
int tc, n, i, cnt;
bool chk[10];

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cnt = 0;
		cin >> n;
		while (n) {
			i = n % 10;
			if (!chk[i]) {
				cnt++;
				chk[i] = true;
			}
			n /= 10;
		}
		cout << '#' << t << ' ' << cnt << '\n';
		memset(chk, 0, sizeof(chk));
	}
	return 0;
}
