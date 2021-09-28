#include<cstdio>
int m[100][100],x,y;
int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&x);
        y=99;
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                scanf("%d",&m[i][j]);
        for(int i=0;i<100;i++)
            if(m[y][i]==2){x=i;	break;}
        while(y){
        	if(x>0&&m[y][x-1]==1)	while(x>0&&m[y][x-1]==1)	x--;
            else if(x<99&&m[y][x+1]==1)	while(x<99&&m[y][x+1]==1)	x++;
            y--;
        }
        printf("#%d %d\n",t,x);
    }
	return 0;
}
