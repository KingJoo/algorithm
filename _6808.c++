#include<cstring>
#include<cstdio>
int tc, c, win, a[9], b[9], f[10];
bool chk[19], ck[9];

void dfs(int depth,int sum) {
	if (sum>85) {
		win+=f[9-depth];
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (!ck[i]) {
			ck[i] = true;
			if(a[depth]>b[i])	dfs(depth + 1,sum+a[depth]+b[i]);
            else	dfs(depth+1,sum);
			ck[i] = false;
		}
	}
}

int main() {
	scanf("%d", &tc);
    for(int i=0;i<=9;i++){
    	f[i]=1;
        for(int j=2;j<=i;j++)
            f[i]*=j;
    }
	for (int t = 1; t <= tc; t++) {
		memset(chk, false, sizeof(chk));
		win = 0;
		for (int i = 0; i < 9; i++) {
			scanf("%d", &c);
			a[i] = c;
			chk[c] = true;
		}
		c = 0;
		for (int i = 1; i < 19; i++)
			if (!chk[i])	b[c++] = i;
		dfs(0,0);
		printf("#%d %d %d\n", t, win, f[9]-win);
	}
	return 0;
}
