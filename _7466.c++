#include<cstdio>
int tc,n,k,r;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d",&n,&k);
        r=1;
        if(n>=k)	r=k;
        else{
            while(n){
            	if(k%n==0){
            		r*=n;
                	k/=n;
                	if(k==1)	break;
                	if(n>k){
                    	n=k;
                    	continue;
                	}
            	}
            	n--;
        	}
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
