#include<stdio.h>
int tc, n;

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
        printf("#%d ", t);
		if (n < 100)	putchar('0');
		else if (n < 1000)	putchar('1');
		else if (n < 10000)	putchar('2');
		else if (n < 100000)	putchar('3');
		else if (n < 1000000)	putchar('4');
		else	putchar('5');
		putchar('\n');
	}
	return 0;
}
