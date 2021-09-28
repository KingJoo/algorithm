#include<cstdio>
int tc,a,b,c,d;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d %d %d",&a,&b,&c,&d);
        a*=d;	b*=c;
        printf("#%d ",t);
        if(a==b)	printf("DRAW");
        else if(a>b)	printf("ALICE");
        else	printf("BOB");
        putchar('\n');
    }
	return 0;
}
