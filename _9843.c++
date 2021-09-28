#include<cstdio>
#include<cmath>
int tc;
long long n,k;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%ld",&n);
        n<<=1;
    	k=pow(n,0.5);
        if(k*(k+1)!=n)	k=-1;
    	printf("#%d %ld\n",t,k);
    }
	return 0;
}
