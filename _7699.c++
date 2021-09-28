#include<cstdio>
int tc,r,c,mx,dx[]={0,0,1,-1},dy[]={1,-1,0,0},xx,yy,mv;
char map[20][21],al[26];
void alRs(){
	for(int i=0;i<26;i++)
        al[i]=0;
    return;
}
void sol(int x,int y,int cnt){
    if(mx==mv)	return;
    if(cnt>mx)	mx=cnt;
    al[map[x][y]-'A']=1;
    for(int i=0;i<4;i++){
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx<0||yy<0||xx==r||yy==c)	continue;
        if(!al[map[xx][yy]-'A'])	sol(xx,yy,cnt+1);
    }
    al[map[x][y]-'A']=0;
    return;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	mx=1;	mv=0;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            scanf("%s",map[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(!al[map[i][j]-'A']){al[map[i][j]-'A']=1;	mv++;}
        alRs();
        sol(0,0,1);
        alRs();
        printf("#%d %d\n",t,mx);
    }
	return 0;
}
