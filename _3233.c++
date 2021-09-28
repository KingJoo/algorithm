#include<cstdio>
int tc,a,b;
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&a,&b);
        a/=b;
        printf("#%d %lld\n",t,a*(long long)a);
    }
    return 0;
}

