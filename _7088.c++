#include<cstdio>
int tc,n,q,l,r,a,N[100001][3];

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
        	scanf("%d",&a);
            a--;
            N[i][0]=N[i-1][0];
            N[i][1]=N[i-1][1];
            N[i][2]=N[i-1][2];
            N[i][a]++;
        }
        printf("#%d\n",t);
        while(q--){
        	scanf("%d%d",&l,&r);
            l--;
            printf("%d %d %d\n",N[r][0]-N[l][0],N[r][1]-N[l][1],N[r][2]-N[l][2]);
        }
    }
	return 0;
}
