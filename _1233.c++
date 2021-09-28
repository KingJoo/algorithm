#include<cstdio>
int n,r,i,k,L,R;
char a[201];
bool od;

int main(){
	for(int t=1;t<=10;t++){
        scanf("%d",&n);
        od=n%2;
        if(od)	r=1;
        else	r=0;
        for(i=1;i<n>>1;i++){
        	scanf("%d %c %d %d",&k,&a[i],&L,&R);
            if(r&&a[i]>='0'&&a[i]<='9')	r=0;
        }
        scanf("%d %c %d",&k,&a[i],&L);
        if(od)	scanf("%d",&R);
        if(r&&a[i]>='0'&&a[i]<='9')	r=0;
        i++;
        for(;i<=n;i++){
        	scanf("%d %c",&k,&a[i]);
            if(r&&(a[i]>'9'||a[i]<'0'))	r=0;
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
