#include<cstdio>
#include<algorithm>
int T,n,k,N[10000],r;
bool cmp(int a,int b){return a>b;}
int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&N[i]);
        if(n<=k)	r=0;
        else{
            std::sort(N,N+n);
        	r=N[n-1]-N[0];
            if(--k){
        		for(int i=n-1;i>0;i--)
            		N[i]-=N[i-1];
            	N[0]=0;
            	std::sort(N,N+n,cmp);
            	for(int i=0;i<k;i++)
                	r-=N[i];
            }
        }
    	printf("#%d %d\n",t,r);
    }
	return 0;
}
