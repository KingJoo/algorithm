#include<cstdio>
typedef long long ll;
int tc,n,h,a[20][2];
ll r;

void dfs(int i,int p,int m,ll x,ll y){
	if(r==0)	return;
    if(i==n){
    	r=r<x*x+y*y?r:x*x+y*y;
        return;
    }
    if(p<h)	dfs(i+1,p+1,m,x+a[i][0],y+a[i][1]);
    if(m<h)	dfs(i+1,p,m+1,x-a[i][0],y-a[i][1]);
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        h=n>>1;
        r=0x07ffffffffffffff;
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i][0],&a[i][1]);
        dfs(0,0,0,0,0);
        printf("#%d %ld\n",t,r);
    }
    return 0;
}
