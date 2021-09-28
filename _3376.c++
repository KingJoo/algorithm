#include<cstdio>
int tc,n;
long long N[101];
int main(){
	N[1]=N[2]=N[3]=1;
    for(int i=4;i<101;i++)
        N[i]=N[i-2]+N[i-3];
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        printf("#%d %lld\n",t,N[n]);
    }
    return 0;
}
