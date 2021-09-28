#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int tc,len;
	bool res;
	string str;
	cin >> tc;
	for (int i = 1; i <= tc;i++) {
		cin >> str;
		len = str.size();
		res = true;
		for (int j = 0; j <= len/2; j++) {
			if (str.at(j) != str.at(len - j - 1)) {
				res = false;
				break;
			}
		}
		cout << '#' << i << ' ' << (int)res << endl;
	}
	return 0;
}
