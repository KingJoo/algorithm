#include<cstdio>
int T,n,k;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d%d",&n,&k);
        printf("#%d %d\n",t,n%k==0?0:1);
    }
	return 0;
}
