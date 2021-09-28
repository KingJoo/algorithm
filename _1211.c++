#include<cstdio>
int n,m[100][100],min,y,x,r;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&n);
        min=0x7fffffff;
        for(int i=0;i<100;i++)
        	for(int j=0;j<100;j++)
                scanf("%d",&m[i][j]);
        for(int i=0;i<100;i++){
        	if(m[0][i]){
                n=y=1;
                x=i;
                while(y<100){
                	if(n>min)	break;
                   	if(x<99&&m[y][x+1])	while(x<99&&m[y][x+1]){x++;n++;}
                    else if(x>0&&m[y][x-1])	while(x>0&&m[y][x-1]){x--;n++;}
                    y++;
                    n++;
                }
                if(min>=n){
                	min=n;
                    r=i;
                }
            }
        }
    	printf("#%d %d\n",t,r);
    }
	return 0;
}
