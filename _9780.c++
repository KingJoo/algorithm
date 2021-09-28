#include<cstdio>
long long r[4];
int T,n,x;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d",&n);
        r[0]=r[1]=r[2]=r[3]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            r[0]=r[1];	r[1]=r[2];	r[2]=r[3];	r[3]=r[0]>r[1]?r[0]:r[1];
            r[3]+=x;
        }
        printf("#%d %ld\n",t,r[2]>r[3]?r[2]:r[3]);
    }
	return 0;
}
