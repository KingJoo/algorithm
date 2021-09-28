#include<stdio.h>

int main() {
	int t, p, q, r, s, w, m, tmp;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d %d %d", &p, &q, &r, &s, &w);
		m = w * p;
		if (w <= r) {
			if (m > q)
				m = q;
		}
		else {
			tmp = q + (w - r) * s;
			if (m > tmp)
				m = tmp;
		}
		printf("#%d %d\n", i, m);
	}
	return 0;
}
