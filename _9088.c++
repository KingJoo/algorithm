#include<cstdio>
#include<algorithm>
int tc,n,k,mx,nn[1001];

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&nn[i]);
        std::sort(nn,nn+n);
        nn[n]=11111;	mx=0;
        for(int i=0;i<n-mx;i++)
        	for(int j=i+1;j<=n;j++)
            	if(nn[j]-nn[i]>k){mx=mx>(j-i)?mx:(j-i);	break;}
    	printf("#%d %d\n",t,mx);
    }
    return 0;
}
