#include<cstdio>
using namespace std;

int main() {
	int t, n, nb, min, cnt;
	scanf("%d",&t);
	for (int i = 1; i <= t; i++) {
		scanf("%d",&n);
		min = 100001;
		cnt = 1;
		for (int j = 0; j < n; j++) {
			scanf("%d",&nb);
			if (nb < 0)	nb = -nb;
			if (nb < min) {
				cnt = 1;
				min = nb;
			}
			else if (nb == min) {
				cnt++;
			}
			else continue;
		}
		printf("#%d %d %d\n",i,min,cnt);
	}
	return 0;
}
