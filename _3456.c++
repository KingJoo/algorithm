#include<cstdio>
int tc,a,b,c,d;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d %d",&a,&b,&c);
        if(a==b)	d=c;
        else if(a==c)	d=b;
        else	d=a;
        printf("#%d %d\n",t,d);
    }
	return 0;
}
