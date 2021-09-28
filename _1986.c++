#include<iostream>
using namespace std;

int main() {
	int tc,n,sum;
	cin >> tc;
	for (int i = 1; i <= tc;i++) {
		cin >> n;
		sum = 0;
		for (int j = 1; j <= n; j++)
			if (j%2)	sum += j;
			else	sum -= j;
		cout<<'#'<<i<<' '<<sum<<'\n';
	}
	return 0;
}
