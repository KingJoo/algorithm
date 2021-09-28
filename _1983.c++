#include<iostream>
using namespace std;

int main() {
	int tc, n, k, stdt[101], t1, t2, t3, b;
	cin >> tc;
	for (int i = 1; i <= tc;i++) {
		cin >> n >> k;
		b = n / 10;
		for (int j = 1; j <= n; j++) {
			cin >> t1 >> t2 >> t3;
			stdt[j] = t1 * 35 + t2 * 45 + t3 * 20;
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (stdt[k] <= stdt[j])
				cnt++;
		if (cnt <= b)	cout << '#' << i << ' ' << "A+" << endl;
		else if (cnt <= b * 2)	cout << '#' << i << ' ' << "A0" << endl;
		else if (cnt <= b * 3)	cout << '#' << i << ' ' << "A-" << endl;
		else if (cnt <= b * 4)	cout << '#' << i << ' ' << "B+" << endl;
		else if (cnt <= b * 5)	cout << '#' << i << ' ' << "B0" << endl;
		else if (cnt <= b * 6)	cout << '#' << i << ' ' << "B-" << endl;
		else if (cnt <= b * 7)	cout << '#' << i << ' ' << "C+" << endl;
		else if (cnt <= b * 8)	cout << '#' << i << ' ' << "C0" << endl;
		else if (cnt <= b * 9)	cout << '#' << i << ' ' << "C-" << endl;
		else	cout << '#' << i << ' ' << "D0" << endl;
	}
	return 0;
}
