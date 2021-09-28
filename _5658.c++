#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char N[29];
bool is;
int tc, n, k, qN, s, tp;
vector<int> v;

int ctoi(char c) {
	if ('0' <= c && c <= '9')	return c - '0';
	else	return c - 'A' + 10;
}

bool cmp(int a, int b){	return a>b;}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		v.clear();
		cin >> n >> k;
		qN = n >> 2;
		cin>>N;
		for (int i = 0; i < n; i++) {
			s = 0;
			for (int j = 0; j < qN; j++) {
				tp = i + j;
				if (tp >= n)	tp %= n;
                s += ctoi(N[tp])*(1<<(((qN - 1 - j)*4-1)+1));
			}
			is = false;
			for (int l = 0; l < v.size(); l++) {
				if (s == v.at(l)) {
					is = true;
					break;
				}
			}
			if (!is)
				v.push_back(s);
		}
		sort(v.begin(), v.end(),cmp);
		cout << '#' << t << ' ' << v.at(k-1) << '\n';
	}
	return 0;
}
