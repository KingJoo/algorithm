#include<cstdio>
#include<algorithm>
int tc,n,k,a[200];
double mx,bm;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        std::sort(a,a+n);
        mx=0;	bm=0.5;
        n--;
        while(k>0){
            mx+=bm*a[n--];
            bm/=2;
            k--;
        }
        printf("#%d %lf\n",t,mx);
    }
    return 0;
}
