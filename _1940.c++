#include<stdio.h>

int main() {
	int t, n, l, ms, op, s, tmp;
	scanf("%d",&t);
	for (int i = 1; i <= t; i++) {
		scanf("%d",&n);
		l = ms = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d",&op);
			if (op != 0) {
				scanf("%d",&tmp);
				if (op == 1)	ms += tmp;
				else {ms -= tmp;if (ms < 0)	ms = 0;}
			}
			l += ms;
		}
		printf("#%d %d\n",i,l);
    }
	return 0;
}
