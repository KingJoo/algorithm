#include<cstdio>
int T,n,m,a[1001],r[1001],b,R,t,i,j;

int main(){
    scanf("%d",&T);
    for(t=1;t<=T;t++){
    	scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++){
            scanf("%d",&b);
            for(j=1;j<=n;j++)
            	if(a[j]<=b){r[j]++;break;}
        }
        R=0;
        for(i=1;i<=n;i++)
        	if(r[R]<r[i])	R=i;
        for(i=1;i<=n;i++)
            r[i]=0;
        printf("#%d %d\n",t,R);
    }
	return 0;
}
