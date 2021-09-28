#include<iostream>
#include<cstring>
using namespace std;
int t, n, a[10][10],way;
enum {RIGHT,UNDER,LEFT,UP};

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			memset(a[j], 0, sizeof(int) * n);
		int b = 0, c = 0, cnt = 1, way = RIGHT;
		while (true) {
			if (n == 1) {
				a[b][c] = cnt;
				break;
			}
			if (way == RIGHT) {
				if (a[b][c] == 0) {
					a[b][c] = cnt;
					cnt++;
					c++;
				}
				if (c == n || a[b][c] != 0) {
					c--;
					if (a[b + 1][c] == 0) {
						way++;
						b++;
					}
					else
						break;
				}
			}
			else if (way == UNDER) {
				if (a[b][c] == 0) {
					a[b][c] = cnt;
					cnt++;
					b++;
				}
				if (b == n || a[b][c] != 0) {
					b--;
					if (a[b][c-1] == 0) {
						way++;
						c--;
					}
					else
						break;
				}
			}
			else if (way == LEFT) {
				if (a[b][c] == 0) {
					a[b][c] = cnt;
					cnt++;
					c--;
				}
				if (c == -1 || a[b][c] != 0) {
					c++;
					if (a[b-1][c] == 0) {
						way++;
						b--;
					}
					else
						break;
				}
			}
			else {
				if (a[b][c] == 0) {
					a[b][c] = cnt;
					cnt++;
					b--;
				}
				if (b == -1 || a[b][c] != 0) {
					b++;
					if (a[b][c+1] == 0) {
						way=RIGHT;
						c++;
					}
					else
						break;
				}
			}
		}
		cout << '#' << i << endl;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++)
				cout << a[j][k] << ' ';
			cout << '\n';
		}
	}
	return 0;
}
