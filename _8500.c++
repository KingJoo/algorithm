#include<iostream>
using namespace std;
int tc, k, tp, mx, sum;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> k;
		sum = k;
		mx = 0;
		for (int i = 0; i < k; i++){
			cin >> tp;
			sum += tp;
			mx = tp > mx ? tp : mx;
		}
		sum += mx;
		cout << '#' << t << ' ' << sum << '\n';
	}
	return 0;
}
