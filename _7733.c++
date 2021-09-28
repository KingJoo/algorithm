#include<cstdio>
bool ck[101];
int tc,n,cz1[100][100],cz2[100][100],cnt,mx,dx[]={0,0,1,-1},dy[]={1,-1,0,0};

void dfs(int y,int x){
    cz2[y][x]=0;
    for(int i=0;i<4;i++){
    	int yy=y+dy[i];
        int xx=x+dx[i];
        if(yy<0||xx<0||yy==n||xx==n)	continue;
        if(cz2[yy][xx])	dfs(yy,xx);
    }
    return;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	mx=1;
        scanf("%d",&n);
        for(int i=1;i<=100;i++)
            ck[i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
            	scanf("%d",&cz1[i][j]);
                if(!ck[cz1[i][j]])	ck[cz1[i][j]]=1;
            }
        for(int i=1;i<=100;i++){
        	if(ck[i]){
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        if(cz1[j][k]==i)	cz1[j][k]=0;
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        cz2[j][k]=cz1[j][k];
                cnt=0;
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        if(cz2[j][k]){
                        	cnt++;
                            dfs(j,k);
                        }
                mx=mx<cnt?cnt:mx;
            }
        }
        printf("#%d %d\n",t,mx);
    }
    return 0;
}
