#include<iostream>
using namespace std;

int tc, n[1024], k, nn, sum, s;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		sum = 0;
		cin >> k;
		nn = (2 << (k - 1));
		for (int i = 0; i < nn; i++)
			cin >> n[i];
		while (k--) {
			s = 0;
			for (int i = 0; i < nn; i += 2) {
				if (n[i] < n[i + 1]) {
					sum += (n[i + 1] - n[i]);
					n[s] = n[i + 1];
				}
				else {
					sum += (n[i] - n[i + 1]);
					n[s] = n[i];
				}
				s++;
			}
			nn >>= 1;
		}
		cout << '#' << t << ' ' << sum << '\n';
	}
	return 0;
}
