#include<cstdio>
#include<algorithm>
int T,N,a[1000],r,t1,t2;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);
        std::sort(a,a+N);
        r=-1;
        for(int i=N-1;i>0;i--){
            if(a[i]*a[i-1]<r)	break;
        	for(int j=i-1;j>=0;j--){
            	t1=a[i]*a[j];
                if(t1<r)	break;
                while(1){
                	t2=t1%10;
                    t1/=10;
                    if(t1==0||t1%10!=t2-1)	break;
                }
                if(t1==0)	r=a[i]*a[j];
            }
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
