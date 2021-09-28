#include<stdio.h>

int main() {
	int i, j, t, n, cnt, tmp;
	char c;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		printf("#%d\n", i);
		scanf("%d", &n);
		cnt = 0;
		for (j = 0; j < n; j++) {
			scanf(" %c %d", &c, &tmp);
			while (tmp--) {
				putchar(c);
				cnt++;
				if (cnt == 10) {
					cnt = 0;
					putchar('\n');
				}
			}
		}
		if (cnt != 0)
			putchar('\n');
	}
	return 0;
}
