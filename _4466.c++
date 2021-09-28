#include<cstdio>
#include<algorithm>
int tc,n,k,N[100],r;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
			scanf("%d",&N[i]);
        r=0;
        if(n==k){
            for(int i=0;i<n;i++)
                r+=N[i];
        }
        else{
        	std::sort(N,N+n);
            while(k--){r+=N[--n];}
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
