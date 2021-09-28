#include<cstdio>
#include<cstring>
int tc, n, s, e, p, tp, bs[5001];

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &s,&e);
			for (int j = s; j <= e; j++)
				bs[j]++;
		}
		scanf("%d", &p);
		printf("#%d ", t);
		for (int i = 0; i < p; i++) {
			scanf("%d", &tp);
			printf("%d ", bs[tp]);
		}
		putchar('\n');
		memset(bs,0,sizeof(bs));
	}
	return 0;
}
