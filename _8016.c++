#include<iostream>
using namespace std;
int tc;
long long n, rS, rE;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		rS = rE = 1;
        cin >> n;
		if(n!=1) {
			n--;
            rS = 2 *( (n * n) + 1) - 1;
			n++;
            rE = 2 * (n * n) - 1;
		}
		cout << '#' << t << ' ' << rS << ' ' << rE << '\n';
	}
	return 0;
}
