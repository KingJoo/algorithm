#include<iostream>
using namespace std;
int tc, sum, maxR, minR, tmp;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		minR = 0x7fffffff; maxR = 0;
		for (int i = 0; i < 10; i++) {
			sum = 0;
			cin >> tmp;
			while (tmp) {
				sum += tmp % 10;
				tmp /= 10;
			}
			minR = minR < sum ? minR : sum;
			maxR = maxR > sum ? maxR : sum;
		}
		cout << '#' << t << ' ' << maxR << ' ' << minR << '\n';
	}
	return 0;
}
