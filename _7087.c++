#include<iostream>
#include<cstring>
using namespace std;
int tc, n, tmp, res;
char str[101];
bool ck['Z' - 'A'];

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			tmp = str[0] - 'A';
			if (!ck[tmp]) ck[tmp] = true;
		}
		res = 0;
		for (int i = 0; i <= 'Z' - 'A'; i++)
			if (ck[i])	res++;
			else	break;
		memset(ck, false, sizeof(ck));
		cout << '#' << t << ' ' << res << '\n';
	}
	return 0;
}
