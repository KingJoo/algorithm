#include<stdio.h>
int n, a[1000], l, r, m, s;
int main() {
	for (int i = 1; i <= 10;i++) {
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		s = 0;
        for (int i = 2;i < n-2;i++) {
			l = a[i - 1]<a[i - 2]?a[i - 2]:a[i - 1];
			if (l < a[i]){
				r = a[i + 1]<a[i + 2]?a[i + 2]:a[i + 1];
				if (r < a[i]){
					m = l<r?r:l;
					if (m < a[i])
						s += (a[i] - m);
                }
            }
		}
        printf("#%d %d\n",i,s);
	}
	return 0;
}
