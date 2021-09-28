#include<iostream>
using namespace std;
int tc, n, tmp, cnt;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cnt = 1;
		cin >> n;
		for (int i = 2; ; i++) {
			tmp = n - i * (i - 1) / 2;
			if (tmp < i)	break;
			if (tmp % i == 0)	cnt++;
		}
		cout << '#' << t << ' ' << cnt << '\n';
	}
	return 0;
}
