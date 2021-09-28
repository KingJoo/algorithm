#include<stdio.h>
int tc, t, d, a, b, f;
double res;

int main() {
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		scanf("%d %d %d %d", &d, &a, &b, &f);
		res = d / ((double)a + b) * f;
		printf("#%d %lf\n", t, res);
	}
	return 0;
}
