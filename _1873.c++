#include<cstdio>
int tc,y,x,n,locY,locX;
char map[20][21], cmd[101];

void _U(){
    map[locY][locX]='^';
    if(locY){
    	if(map[locY-1][locX]=='.'){
       		map[locY][locX]='.';
        	map[--locY][locX]='^';
    	}
    }
    return;
}
void _D(){
	map[locY][locX]='v';
    if(locY<y-1){
    	if(map[locY+1][locX]=='.'){
            map[locY][locX]='.';
            map[++locY][locX]='v';
        }
    }
    return;
}
void _L(){
	map[locY][locX]='<';
    if(locX){
    	if(map[locY][locX-1]=='.'){
            map[locY][locX]='.';
            map[locY][--locX]='<';
        }
    }
    return;
}
void _R(){
	map[locY][locX]='>';
    if(locX<x-1){
    	if(map[locY][locX+1]=='.'){
            map[locY][locX]='.';
            map[locY][++locX]='>';
        }
    }
    return;
}
void _S(){
    if(map[locY][locX]=='^'&&locY){
       	for(int i=locY-1;i>=0;i--){
           	if(map[i][locX]=='#')	break;
            else if(map[i][locX]=='*'){
            	map[i][locX]='.';
               	break;
            }
       	}
    }
    else if(map[locY][locX]=='v'&&locY<y-1){
       	for(int i=locY+1;i<y;i++){
           	if(map[i][locX]=='#')	break;
            else if(map[i][locX]=='*'){
            	map[i][locX]='.';
               	break;
            }
       	}
    }
    else if(map[locY][locX]=='<'&&locX){
       	for(int i=locX-1;i>=0;i--){
           	if(map[locY][i]=='#')	break;
            else if(map[locY][i]=='*'){
            	map[locY][i]='.';
               	break;
            }
       	}
    }
    else if(map[locY][locX]=='>'&&locX<x-1){
       	for(int i=locX+1;i<x;i++){
           	if(map[locY][i]=='#')	break;
            else if(map[locY][i]=='*'){
            	map[locY][i]='.';
               	break;
            }
       	}
    }
    return;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&y,&x);
        for(int i=0;i<y;i++){
            scanf("%s",map[i]);
        	for(int j=0;j<x;j++)
                if(map[i][j]=='v'||map[i][j]=='<'||map[i][j]=='>'||map[i][j]=='^'){	locY=i;	locX=j;}
        }
        scanf("%d %s",&n,cmd);
        for(int i=0;i<n;i++){
        	if(cmd[i]=='U')	_U();
            else if(cmd[i]=='D')	_D();
            else if(cmd[i]=='L')	_L();
            else if(cmd[i]=='R')	_R();
            else	_S();
        }
        printf("#%d ",t);
        for(int i=0;i<y;i++)
        	printf("%s\n",map[i]);
    }
	return 0;
}
