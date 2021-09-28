#include<cstdio>
int tc,n,x;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d",&n,&x);
        printf("#%d ",t);
        if(x==1||x==(n<<1)-1)	putchar('0');
        else	putchar('1');
        putchar('\n');
    }
	return 0;
}
