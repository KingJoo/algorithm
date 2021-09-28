#include<cstdio>
bool a[501][501];
int tc,n,m,t1,t2,c,cc;

void D(int s){
	if(cc==n)	return;
    for(int i=1;i<=n;i++)
        if(a[s][i]&&!a[0][i]){
            a[0][i]=1;
            cc++;
            D(i);
        }
}

void U(int s){
    if(cc==n)	return;
	for(int i=1;i<=n;i++)
        if(a[i][s]&&!a[0][i]){
            a[0][i]=1;
            cc++;
            U(i);
        }
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
        	scanf("%d%d",&t1,&t2);
            a[t1][t2]=1;
        }
        c=0;
        for(int i=1;i<=n;i++){
            cc=a[0][i]=1;
            D(i); U(i);
            if(cc==n)	c++;
            for(int j=1;j<=n;j++)
                a[0][j]=0;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=0;
        printf("#%d %d\n",t,c);
    }
    return 0;
}
