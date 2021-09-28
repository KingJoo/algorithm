#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int t, n, a[] = {2,3,5,7,11}, b[5];
	scanf("%d",&t);
	for (int i = 1; i <= t; i++) {
		scanf("%d",&n);
		memset(b, 0, sizeof(int) * 5);
		for (int j = 0; j < 5; j++) {
			while (true) {
				if (n % a[j]==0) {
					n /= a[j];
					b[j]++;
				}
				else break;
			}
		}
		printf("#%d ",i);
		for (int j = 0; j < 5; j++)
			printf("%d ",b[j]);
		putchar('\n');
	}
	return 0;
}
