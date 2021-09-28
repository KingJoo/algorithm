#include<cstdio>
int tc,n,x,y,r,p[]={200,180,160,140,120,100,80,60,40,20};

int score(int dist){
	int i=0;
    for(;i<10;i++)
    	if(dist>p[i])	break;
    return i;
}

int main(){
    for(int i=0;i<10;i++)
        p[i]*=p[i];
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	r=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            r+=score(x*x+y*y);
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
