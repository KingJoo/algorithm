#include<cstdio>
int tc;
long long n;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%ld",&n);
        printf("#%ld %ld %ld %ld\n",t,((n+1)*n)/2,n*n,(n+1)*n);
    }
	return 0;
}
