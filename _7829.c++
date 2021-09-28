#include<cstdio>
int tc,n,m,mn,mx;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d",&n,&m);
        mx=mn=m;
        for(int i=1;i<n;i++){
        	scanf("%d",&m);
            mx=mx>m?mx:m;
            mn=mn<m?mn:m;
        }
        printf("#%d %d\n",t,mx*mn);
    }
	return 0;
}
