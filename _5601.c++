#include<cstdio>
int tc,n;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        printf("#%d",t);
        for(int i=0;i<n;i++)
            printf(" 1/%d",n);
        putchar('\n');
    }
    return 0;
}
