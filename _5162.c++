#include<cstdio>
int tc,a,b,c;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d %d",&a,&b,&c);
        if(a>b)	c/=b;
        else	c/=a;
        printf("#%d %d\n",t,c);
    }
    return 0;
}
