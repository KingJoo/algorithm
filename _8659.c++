#include<cstdio>
int tc,k;
long long r[91]={1,2,};
int main(){
	for(int i=2;i<=90;i++)
        r[i]=r[i-1]+r[i-2];
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&k);
    	printf("#%d %ld %ld\n",t,r[k],r[k-1]);
    }
	return 0;
}
