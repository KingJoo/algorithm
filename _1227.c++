#include<cstdio>
char map[100][100];
int n,a,b,dx[]={0,0,1,-1},dy[]={1,-1,0,0},res;

void dfs(int y, int x){
    if(res)	return;
	for(int i=0;i<4;i++){
    	int yy=y+dy[i];
        int xx=x+dx[i];
        if(yy<0||xx<0||yy==100||xx==100)	continue;
        if(map[yy][xx]=='3'){
            res=1;
            return;
        }
        if(map[yy][xx]=='0'){
        	map[yy][xx]='1';
            dfs(yy,xx);
            map[yy][xx]='0';
        }
    }
}

int main(){
	for(int t=1;t<=10;t++){
    	res=0;
        scanf("%d",&n);
        for(int i=0;i<100;i++){
            getchar();
            for(int j=0;j<100;j++){
            	map[i][j]=getchar();
                if(map[i][j]=='2'){
                	a=i;	b=j;
                }
            }
        }
        dfs(a,b);
        printf("#%d %d\n",n,res);
    }
    return 0;
}
