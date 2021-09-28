#include<iostream>
using namespace std;

int main() {
	int t, h, m, h1, h2, m1, m2;;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> h1 >> m1 >> h2 >> m2;
		h = h1 + h2;
		m = m1 + m2;
		if (m > 59) {
			m -= 60;
			h++;
		}
		if (h > 12)
			h -= 12;
		cout << '#' << i << ' ' << h << ' ' << m << endl;
	}
	return 0;
}
