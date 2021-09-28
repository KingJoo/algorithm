#include<iostream>
using namespace std;
int tc, h1, m1, s1, h2, m2, s2;
char str[9];

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> str;
		h1 = (str[0] - '0') * 10 + (str[1] - '0');
		m1 = (str[3] - '0') * 10 + (str[4] - '0');
		s1 = (str[6] - '0') * 10 + (str[7] - '0');
		cin >> str;
		h2 = (str[0] - '0') * 10 + (str[1] - '0');
		m2 = (str[3] - '0') * 10 + (str[4] - '0');
		s2 = (str[6] - '0') * 10 + (str[7] - '0');
		s2 -= s1;
		if (s2 < 0) {
			s2 += 60;
			m2--;
		}
		m2 -= m1;
		if (m2 < 0) {
			m2 += 60;
			h2--;
		}
		h2 -= h1;
		if (h2 < 0)
			h2 += 24;
		cout << '#' << t << ' ';
		if (h2 < 10)	cout << '0';
		cout << h2 << ':';
		if (m2 < 10)	cout << '0';
		cout << m2 << ':';
		if (s2 < 10)	cout << '0';
		cout << s2 << '\n';
	}
	return 0;
}
