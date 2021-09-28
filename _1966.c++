#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t, n, a[50];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> a[j];
		sort(a,a+n);
		cout << '#' << i << ' ';
		for (int j = 0; j < n; j++)
			cout << a[j] << ' ';
		cout<< endl;
	}
	return 0;
}
