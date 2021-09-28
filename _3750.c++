#include<cstdio>
int tc;
long long n;

int f(long long k){
	int a=0;
    while(k){
    	a+=k%10;
        k/=10;
    }
    return a;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%ld",&n);
        while(true){
        	n=f(n);
            if(n<10)	break;
        }
        printf("#%d %d\n",t,n);
    }
	return 0;
}
