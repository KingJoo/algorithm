#include<cstdio>
#include<cstring>
int tc,n,k,K;
bool N[101];
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&n,&k);
        for(int i=1;i<=k;i++){
        	scanf("%d",&K);
            N[K]=true;
        }
        printf("#%d ",t);
        for(int i=1;i<=n;i++)
        	if(!N[i])
                printf("%d ",i);
        putchar('\n');
        memset(N,false,sizeof(N));
    }
	return 0;
}
