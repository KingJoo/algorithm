#include<cstdio>
int tc,n,m,cnt,a,b;
bool c[101][101],d[101];

void find(int z){
	d[z]=1;
    for(int i=1;i<=n;i++)
    	if(c[z][i]&&!d[i])	find(i);
    return;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
        	scanf("%d %d",&a,&b);
            c[a][b]=c[b][a]=1;
        }
        cnt=0;
        for(int i=1;i<=n;i++){
        	if(!d[i]){
                cnt++;
                find(i);
            }
        }
        for(int i=1;i<=n;i++){
            d[i]=0;
        	for(int j=1;j<=n;j++)
                c[i][j]=0;
        }
    	printf("#%d %d\n",t,cnt);
    }
	return 0;
}
