#include<iostream>
#include<cstring>
using namespace std;

int cnt,len,tmp;
bool chk[10];

int main() {
	int tc;
	string str;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cnt = 0;
		memset(chk,0,sizeof(chk));
		cin >> str;
		len = str.size();
		for (int i = 0; i < len; i++) {
			tmp = str.at(i) - '0';
			chk[tmp] = !chk[tmp];
		}
		for (int i = 0; i < 10; i++) {
			if (chk[i])
				cnt++;
		}
		cout << '#' << t << ' ' << cnt << '\n';
	}
	return 0;
}
