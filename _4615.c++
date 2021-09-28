#include<cstdio>
#include<cstring>
int tc,n,m,hn,x,y,c,b,h,map[8][8],ban,xx,yy;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={1,0,-1,1,-1,1,0,-1};

bool chk(int x,int y,int way){
	while(true){
    	x+=dx[way];
    	y+=dy[way];
        if(x>=n||y>=n||x<0||y<0)	return false;
        if(map[y][x]==c)	return true;
        else if(map[y][x]==ban)	continue;
        else	return false;
    }
}

void proc(int x,int y){
    if(c==1)	ban=2;
    else	ban=1;
    map[y][x]=c;
    for(int i=0;i<8;i++){
    	xx=x+dx[i];
        yy=y+dy[i];
        if(xx<0||yy<0||xx>=n||yy>=n)	continue;
        if(map[yy][xx]==ban){
        	if(chk(xx,yy,i)){
            	while(true){
               		if(map[yy][xx]==c)	break;
                	else	map[yy][xx]=c;
                	xx+=dx[i];
               		yy+=dy[i];
            	}
            }
        }
    }
    return;
}

int main(){
	scanf("%d",&tc);
   	for(int t=1;t<=tc;t++){
   		scanf("%d %d",&n,&m);
        hn=n>>1;
        map[hn][hn]=2;
        map[hn][hn-1]=1;
        map[hn-1][hn]=1;
        map[hn-1][hn-1]=2;
        for(int i=0;i<m;i++){
        	scanf("%d %d %d",&x,&y,&c);
            proc(x-1,y-1);
        }
        b=h=0;
   		for(int i=0;i<n;i++)
   	    	for(int j=0;j<n;j++)
   	        	if(map[i][j]==1)	b++;
   	 			else if(map[i][j]==2)	h++;
   		printf("#%d %d %d\n",t,b,h);
		memset(map,0,sizeof(map));
    }
    return 0;
}
