#include<cstdio>
int tc,n,m=1e9,dp[101][10][1<<10],bm;
long long r;

int main(){
    for(int e=1;e<10;e++)
        dp[1][e][1<<e]=1;
    for(int l=2;l<101;l++)
        for(int e=0;e<10;e++)
            for(int b=0;b<0x400;b++){
            	bm=b|(1<<e);
                if(e>0)	dp[l][e][bm]+=dp[l-1][e-1][b];
                if(e<9)	dp[l][e][bm]+=dp[l-1][e+1][b];
                dp[l][e][bm]%=m;
            }
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        r=0;
        for(int e=0;e<10;e++)
            r+=dp[n][e][0x3ff];
    	printf("#%d %d\n",t,r%m);
    }
	return 0;
}
