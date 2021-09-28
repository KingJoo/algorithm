#include<cstdio>
int tc,a,b,c,r;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d %d",&a,&b,&c);
        if(b<c)	r=-1;
        else if(c<a)	r=a-c;
        else r=0;
        printf("#%d %d\n",t,r);
    }
	return 0;
}
