#include<iostream>
using namespace std;
string str;
const int c = 1000000007;
int tc, len;
long long cnt;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cnt = 1;
		cin >> str;
		len = str.size();
		if (str.at(0) != str.at(1))	cnt = 2;
		for (int i = 1; i < len - 1;i++) {
			if (str.at(i-1) != str.at(i))
				if (str.at(i) != str.at(i + 1))
					if (str.at(i - 1) != str.at(i + 1))	cnt *= 3;
					else	cnt <<= 1;
				else	cnt <<= 1;
			else
				if (str.at(i) != str.at(i + 1))	cnt <<= 1;
			if (cnt >= c)	cnt %= c;
		}
		if (str.at(len-1) != str.at(len-2))	cnt <<= 1;
		if (cnt >= c)	cnt %= c;
		cout << '#' << t << ' ' << cnt << '\n';
	}
	return 0;
}
