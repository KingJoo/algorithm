#include<cstdio>
int tc, n, m;
double sum, tp;

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf %d", &tp,&m);
			sum += (tp * m);
		}
		printf("#%d %lf\n", t, sum);
	}
	return 0;
}
