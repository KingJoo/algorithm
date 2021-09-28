#include<iostream>
using namespace std;

int main() {
	int m[] = {50000,10000,5000,1000,500,100,50,10};
	int t, money, n, c[8];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> money;
		for (int j = 0; j < 8; j++) {
			n = money / m[j];
			if (n) {
				c[j] = n;
				money %= m[j];
			}
			else
				c[j] = 0;
		}
		cout << '#' << i << endl;
		for (int j = 0; j < 8; j++)
			cout << c[j] << ' ';
		cout << endl;
	}
	return 0;
}
