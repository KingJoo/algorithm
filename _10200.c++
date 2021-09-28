#include<cstdio>
int T,n,a,b;
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d%d%d",&n,&a,&b);
        printf("#%d %d %d\n",t,a>b?b:a,a+b-n<0?0:a+b-n);
    }
	return 0;
}
