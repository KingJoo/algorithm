#include<iostream>
using namespace std;
int tc, res, tmp, n, b, e, rm;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		res = 0;
		cin >> n >> b >> e;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
            rm=b % tmp;
			if (rm <= e || rm+e>=tmp)
				res++;
		}
		cout << '#' << t << ' ' << res << '\n';
	}
	return 0;
}
