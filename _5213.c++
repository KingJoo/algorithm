#include<cstdio>
#define N 1000001
long long f[N];
int tc,l,r;

int main(){
	for(int i=1;i<N;i+=2){
    	for(int j=i;j<N;j+=i)
            f[j]+=i;
        f[i]+=f[i-1];
        f[i+1]+=f[i];
    }
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d",&l,&r);
        printf("#%d %ld\n",t,f[r]-f[--l]);
    }
	return 0;
}
