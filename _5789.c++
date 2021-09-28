#include<cstdio>
#include<cstring>
int tc,n,q,l,r,a[1001];
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	memset(a,0,sizeof(a));
        scanf("%d %d",&n,&q);
        for(int i=1;i<=q;i++){
        	scanf("%d %d",&l,&r);
           	for(int j=l;j<=r;j++)
                a[j]=i;
        }
        printf("#%d ",t);
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        putchar('\n');
    }
	return 0;
}
