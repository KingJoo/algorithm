#include<iostream>
using namespace std;
int tc, e, bm, bj, tbm, tbj, n;

int main() {
	cin >> tc;
	string str;
	for (int t = 1; t <= tc; t++) {
		n = 0;
		cin >> str;
		e = str.size() - 1;
		if (str.at(e) == 'h') {
			bj = 0;
			e -= 5;
		}
		else {
			bj = 90;
			e -= 4;
		}
		bm = 1;
		while (e != -1) {
			tbj = 90;
			tbm = 2 << n;
			n++;
			//north -
			if (str.at(e) == 'h') {
				if (bm > tbm) {
					while (bm != tbm) {
						tbm <<= 1;
						tbj <<= 1;
					}
				}
				else if(bm < tbm){
					while (bm != tbm) {
						bm <<= 1;
						bj <<= 1;
					}
				}
				bj -= tbj;
				e -= 5;
			}
			//west +
			else {
				if (bm > tbm) {
					while (bm != tbm) {
						tbm <<= 1;
						tbj <<= 1;
					}
				}
				else if (bm < tbm) {
					while (bm != tbm) {
						bm <<= 1;
						bj <<= 1;
					}
				}
				bj += tbj;
				e -= 4;
			}
		}
		while (true) {
			if (bm == 1 || bj & 0x1)
				break;
			bm >>= 1;
			bj >>= 1;
		}
		if (bm == 1)
			cout << '#' << t << ' ' << bj << '\n';
		else
			cout << '#' << t << ' ' << bj << '/' << bm << '\n';
	}
	return 0;
}
