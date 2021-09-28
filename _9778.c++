#include<cstdio>
int tc,n,c[12],p,T,C,i;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	for(i=2;i<12;i++)
            c[i]=4;
        c[10]<<=2;	p=21;	C=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&T);
            c[T]--;
            p-=T;
        }
    	for(i=2;i<=p;i++)
        	C+=c[i];
        printf("#%d ",t);
        if(52-n>=C<<1)	printf("STOP\n");
        else	printf("GAZUA\n");
    }
	return 0;
}
