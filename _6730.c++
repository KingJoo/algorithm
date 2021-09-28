#include<stdio.h>
int t, i, tc, n, up, down, pre, aft, m;

int main() {
	scanf("%d",&tc);
	for (t = 1; t <= tc; t++) {
		scanf("%d",&n);
		up = down = 0;
		scanf("%d",&pre);
		for (i = 1; i < n; i++) {
			scanf("%d",&aft);
			m = pre - aft;
			if (m == 0)	continue;
			else if (m<0) {	m = -m;	up = up > m ? up : m; }
			else	down = down > m ? down : m;
			pre = aft;
		}
		printf("#%d %d %d\n",t,up,down);
	}
	return 0;
}
