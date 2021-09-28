#include<stdio.h>
int tc,t,o,i,k,m,a[100000];
long long s;

int main(){
    scanf("%d",&tc);
    for(t=1;t<=tc;t++){
    	scanf("%d,",&k);
        o=-1; s=0;
        for(i=0;i<k;i++){
        	scanf("%d",&m);
            if(m)	a[++o]=m;
            else	o--;
        }
        for(i=0;i<=o;i++)
            s+=a[i];
        printf("#%d %ld\n",t,s);
    }
    return 0;
}
