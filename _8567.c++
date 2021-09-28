#include<cstdio>
#define M 100001
int tc,n,a[M],b,c,m=1;
bool s[M];

int main(){
    for(int i=2;i<M;i++)
        if(!s[i])
            for(int j=(i<<1);j<M;j+=i)
                s[j]=1;
    for(int i=1;i<M;i++)
        a[i]=1;
    for(int i=2;i<M;i++)
        if(!s[i])
            for(int j=i;j<M;j+=i){
            	b=j; c=1;
            	while(b%i==0){b/=i; c++;}
            	a[j]*=c;
        	}
    for(int i=2;i<M;i++){
    	if(m==a[i])	a[i]=i;
        else if(m>a[i])	a[i]=a[i-1];
        else{m=a[i]; a[i]=i;}
    }
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        printf("#%d %d\n",t,a[n]);
    }
    return 0;
}
