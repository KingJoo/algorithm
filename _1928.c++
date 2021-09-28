#include<iostream>
using namespace std;

int main() {
	int t;
	char buf1[4], buf2[3];
	string s;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		int size = s.size();
		cout << '#' << i << ' ';
		for (int j = 0; j < size; j+=4) {
			for (int k = 0; k < 4; k++) {
				buf1[k] = s.at(j + k);
				if ('A' <= buf1[k] && buf1[k] <= 'Z')
					buf1[k] -= 'A';
				else if ('a' <= buf1[k] && buf1[k] <= 'z')
					buf1[k] -= ('a' - 26);
				else if ('0' <= buf1[k] && buf1[k] <= '9')
					buf1[k] -= ('0' - 52);
				else if (buf1[k] == '+')
					buf1[k] = 62;
				else if (buf1[k] == '/')
					buf1[k] = 63;
			}
			buf2[0] = (buf1[0] << 2) + (buf1[1] >> 4);
			buf2[1] = (buf1[1] << 4) + (buf1[2] >> 2);
			buf2[2] = (buf1[2] << 6) + buf1[3];
			cout << buf2;
		}
		cout << endl;
	}
	return 0;
}
