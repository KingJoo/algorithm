#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
char tp[101];
int tc,n,res,tmp,x,y,xx,yy,map[100][100],ck[100][100],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
queue<pair<int,int>> q;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",tp);
            for(int j=0;j<n;j++)
            	map[i][j]=tp[j]-'0';
        }
    	for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ck[i][j]=-1;
        q.push({0,0});
        ck[0][0]=0;
    	while(q.size()){
    		y=q.front().first;
        	x=q.front().second;
        	q.pop();
        	for(int i=0;i<4;i++){
        		yy=y+dy[i];
            	xx=x+dx[i];
            	if(yy<0||xx<0||yy==n||xx==n)	continue;
                tmp=ck[y][x]+map[yy][xx];
                if(ck[yy][xx]==-1){
                    ck[yy][xx]=tmp;
                	q.push({yy,xx});
                }
                else{
                    if(ck[yy][xx]>tmp){
                    	ck[yy][xx]=tmp;
                        q.push({yy,xx});
                    }
                }
        	}
    	}
        printf("#%d %d\n",t,ck[n-1][n-1]);
    }
	return 0;
}
