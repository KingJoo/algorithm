#include<iostream>
using namespace std;
int tc, n, tmp, res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		cin >> res;
		for (int i = 1; i < n; i++) {
			cin >> tmp;
			if (tmp == 0)
				continue;
			else if (tmp == 1) {
				res++;
				continue;
			}
			if (res < 2)
				res += tmp;
			else
				res *= tmp;
		}
		cout << '#' << t << ' ' << res << '\n';
	}
	return 0;
}
