#include<cstdio>
int tc,n,si,k;
long long r1,t1,r2,t2,e=1e14;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	r1=r2=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
        	scanf("%d",&si);
            k=si%10;
            si/=10;
            t1=0;
            t2=1;
            while(k--){
                if(t1!=0)	t1*=si;
                t2*=si;
                if(t2>=e){
                    t1+=(t2/e);
                    t2%=e;
                }
            }
            r1+=t1;
            r2+=t2;
        }
        if(r2>=e){
            r1+=(r2/e);
            r2%=e;
        }
    	printf("#%d ",t);
        if(r1!=0){
            printf("%ld",r1);
            r1=r2;
            k=0;
            if(r1==0)	k++;
            while(r1){
            	r1/=10;
                k++;
            }
            for(int i=0;i<14-k;i++)
                putchar('0');
        }
        printf("%ld\n",r2);
    }
    return 0;
}
