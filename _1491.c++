#include<cstdio>
#include<cmath>
int T,r,c;
long long n,a,b,m,mm;

int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d %d",&n,&a,&b);
        r=c=pow((double)n,(double)1/2);
        m=b*(n-r*c);
        int i=r;
        while(true){
        	if(c<=0)	break;
            i++;
            if(i*c>n){
                c--;
                if(c<=0)	break;
                continue;
            }
            int sc=c;
            while(true){
            	mm=a*(i-sc)+b*(n-i*sc);
                if(mm<m)	m=mm;
                else break;
                sc--;
                if(sc<=0)	break;
            }
        }
        printf("#%d %lld\n",t,m);
    }
    return 0;
}
