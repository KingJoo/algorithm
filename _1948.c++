#include<iostream>
using namespace std;

int main() {
	int t, cnt, m1, d1, m2, d2;
	int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cnt = 0;
		cin >> m1 >> d1 >> m2 >> d2;
		cnt = d2 - d1 + 1;
		if(m1!=m2)
			for (int j = m1; j < m2; j++)
				cnt += m[j];
		cout << '#' << i << ' ' << cnt << endl;
	}
	return 0;
}
