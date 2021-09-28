#include<cstdio>
int T,n;

int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d",&n);
        n<<=1;
        printf("#%d %d %d\n",t,n/60,n%60);
    }
	return 0;
}
