#include<cstdio>
int T,n,k,f[11]={1,},a[11];
long long sc[11][101],u;

void dfs(int d,int s){
	if(d==n+1){
        sc[n][s]++;
        return;
    }
    for(int i=1;i<=n;i++){
    	if(!a[i]){
        	a[i]=1;
            dfs(d+1,s+(d>i?d:i));
            a[i]=0;
        }
    }
}

int main(){
    for(int i=1;i<11;i++){
        f[i]=f[i-1]*i;
    	n=i;
        dfs(1,0);
    }
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&n,&k);
        u=0;
        for(int i=k;i<101;i++)
            u+=sc[n][i];
        printf("#%d %ld\n",t,f[n]*u);
    }
    return 0;
}
