#include<iostream>
using namespace std;
int big, small,* s, * b;

int main() {
	int t, n, m, nn[20], mm[20], total;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		for (int j = 0; j < n; j++)
			cin >> nn[j];
		for (int j = 0; j < m; j++)
			cin >> mm[j];
		if (n >= m) {
			big = n;
			small = m;
			b = nn;
			s = mm;
		}
		else {
			big = m;
			small = n;
			b = mm;
			s = nn;
		}
		int max = 0x80000000;
		for (int j = 0; j <= big - small; j++) {
			total = 0;
			for (int k = 0; k < small; k++)
				total += (b[j + k] * s[k]);
			if (total > max)
				max = total;
		}
		cout << '#' << i << ' ' << max << endl;
	}
	return 0;
}
