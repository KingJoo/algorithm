#include<cstdio>
int tc,n,r,a,b,c,d;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d%d%d",&a,&b,&c,&d);
        a-=c;	b-=d;	r=0;
        if(a<0)	a=-a;
        if(b<0)	b=-b;
        if(a>b){
            c=a;	a=b;	b=c;
        }
        r+=(a<<1);
        b-=a;
        if(b%2)	r+=((b<<1)-1);
        else	r+=(b<<1);
        printf("#%d %d\n",t,r);
    }
	return 0;
}
