#include<iostream>
using namespace std;

int main() {
	int tc,n,sum,min,max;
	cin >> tc;
	for (int i = 1; i <= tc;i++) {
		sum = 0;
		min = 10000;
		max = 0;
		for(int j=0;j<10;j++){
			cin >> n;
			if (n < min)	min = n;
			if (n > max)	max = n;
			sum += n;
		}
		sum -= (max + min);
		if (sum % 8 >= 4) {
			sum /= 8;
			sum++;
		}
		else
			sum /= 8;
		cout << '#' << i << ' ' <<sum << endl;
	}
	return 0;
}
