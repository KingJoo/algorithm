#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int t, n, cnt, chkN, tmpN;
    bool chk[10];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		memset(chk, 0, sizeof(chk));
        chkN = cnt = 0;
		while (chkN!=10) {
            cnt++;
			tmpN = n * cnt;
			while (tmpN) {
				if(!chk[tmpN % 10]) {
                    chk[tmpN % 10] = true;
                    chkN++;
                }
				tmpN /= 10;
			}
		}
		cout << '#' << i << ' ' << n * cnt << endl;
	}
	return 0;
}
