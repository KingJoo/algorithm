#include<cstdio>
int tc, n, m, t1, t2, cnt;
bool a[51][51];

int main() {
	scanf("%d",&tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d",&n,&m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d",&t1,&t2);
			a[t1][t2] = a[t2][t1] = true;
		}
		cnt = 0;
		for (int i = 1; i <= n-2; i++)
			for (int j = i+1; j <= n-1; j++)
				if (a[i][j])
                    for (int k = j + 1; k <= n; k++)
						if (a[j][k]&&a[k][i])	cnt++;
		printf("#%d %d\n",t,cnt);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = false;
	}
	return 0;
}
