#include<cstdio>
#define S 1000001
#define M 1000000007
int tc,N;
long long n[S],a,b,r;

int main(){
	for(int i=1;i<S;i++){
    	a=b=i;
        r=1;
    	while(b!=0){
        	if(b&1)	r=(r*a)%M;
        	a=(a*a)%M;
        	b>>=1;
    	}
        n[i]=n[i-1]+r;
    }
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&N);
        printf("#%d %d\n",t,n[N]%M);
    }
	return 0;
}
