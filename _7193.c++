#include<iostream>
#include<cstring>
using namespace std;
int tc, n, len, res;
char str[10000001];

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> str;
		len = strlen(str);
		res = 0;
		for (int i = 0; i < len; i++)
			res += (str[i] - '0');
		n--;
        res %= n;
		cout << '#' << t << ' ' << res << '\n';
	}
	return 0;
}
