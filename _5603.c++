#include<cstdio>
int tc,n,nn[10000],a,r;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        a=r=0;
        for(int i=0;i<n;i++){
            scanf("%d",&nn[i]);
        	a+=nn[i];
        }
        a/=n;
        for(int i=0;i<n;i++)
        	if(a-nn[i]>0)	r+=a-nn[i];
        printf("#%d %d\n",t,r);
    }
	return 0;
}
