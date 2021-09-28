#include<iostream>
using namespace std;

bool chk[10];

bool check() {
	bool v = true;
	for (int i = 1; i < 10; i++) {
		if (chk[i])
			continue;
		else {
			v = false;
			break;
		}
	}
	for (int i = 1; i < 10; i++)
		chk[i] = false;
	return v;
}

int main() {
	int t;
	int sd[9][9];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		bool valid = true;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
				cin >> sd[a][b];
		for (int a = 0; a < 9; a++) {
			for (int b = 0; b < 9; b++)
				chk[sd[a][b]] = true;
			valid = check();
			if (!valid)	break;
		}
		if (valid) {
			for (int a = 0; a < 9; a++) {
				for (int b = 0; b < 9; b++)
					chk[sd[b][a]] = true;
				valid = check();
				if (!valid)	break;
			}
		}
		if (valid) {
			for (int a = 0; a < 9; a = a + 3) {
				for (int b = 0; b < 9; b = b + 3) {
					if (valid) {
						for (int c = 0; c < 3; c++)
							for (int d = 0; d < 3; d++)
								chk[sd[a+c][b+d]] = true;
						valid = check();
					}
					else break;
				}
				if (!valid)	break;
			}
		}
		cout << '#' << i << ' ' << (int)valid << endl;
	}
	return 0;
}
