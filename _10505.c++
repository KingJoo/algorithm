#include<cstdio>
int T,n,a[10000],c;
double s;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d",&n);
        s=c=0;
        for(int i=0;i<n;i++){
        	scanf("%d",&a[i]);
            s+=a[i];
        }
        s/=n;
        for(int i=0;i<n;i++)
        	if(a[i]<=s)	c++;
    	printf("#%d %d\n",t,c);
    }
	return 0;
}
