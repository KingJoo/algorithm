#include<iostream>
using namespace std;
int arr[11], n;

int main() {
	int tc, tmp1, tmp2;
	cin >> tc;
	for (int s = 1; s <= tc; s++) {
		for (int i = 0; i < 11; i++)	arr[i] = 1;
		cin >> n;
		cout << '#' << s << ' ' << endl;
		if (n < 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= i; j++)
					cout << arr[j] << ' ';
				putchar('\n');
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j <= i; j++)
					cout << arr[j] << ' ';
				putchar('\n');
			}
			for (int i = 2; i < n ; i++) {
				tmp1 = arr[0];
				tmp2 = arr[1];
				for (int j = 1; j < i; j++) {
					arr[j] = tmp1 + tmp2;
					tmp1 = tmp2;
					tmp2 = arr[j + 1];
				}
				for (int j = 0; j <= i; j++)
					cout << arr[j] << ' ';
				putchar('\n');
			}
		}
	}
	return 0;
}
