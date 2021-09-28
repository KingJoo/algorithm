#include<cstdio>
int tc,n,m;
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&n,&m);
        n=(m<<1)-n;
        printf("#%d %d %d\n",t,n,m-n);
    }
    return 0;
}

