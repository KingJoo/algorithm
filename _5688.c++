#include <cmath>
#include <cstdio>
int tc, tmp;
long long n;

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%ld", &n);
		tmp = cbrt(n);
		if (pow(tmp + 1, 3) == n)	tmp += 1;
		if (pow(tmp, 3) != n)	tmp = -1;
		printf("#%d %d\n", t, tmp);
	}
	return 0;
}
