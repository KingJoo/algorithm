#include<iostream>
using namespace std;

int main() {
	int t, n, a[7][7], _90[7][7], _180[7][7], _270[7][7];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				cin >> a[j][k];

		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				_90[k][n - 1 - j] = a[j][k];

		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				_180[n - 1 - j][n - 1 - k] = a[j][k];

		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				_270[n-1-k][j] = a[j][k];

		cout << '#' << i << endl;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				cout << _90[j][k];
			cout << ' ';
			for (int k = 0; k < n; k++)
				cout << _180[j][k];
			cout << ' ';
			for (int k = 0; k < n; k++)
				cout << _270[j][k];
			cout << endl;
		}
	}
	return 0;
}
