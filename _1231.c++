#include<cstdio>
char d[101];
int n,hn,m;
bool odd;

void dfs(int a){
    if(a<<1<=n)	dfs(a<<1);
    printf("%c",d[a]);
    if((a<<1)+1<=n)	dfs((a<<1)+1);
}

int main(){
	for(int t=1;t<=10;t++){
        scanf("%d",&n);
        hn=n>>1;	odd=true;
        if(n%2)	odd=false;
        for(int i=1;i<=n;i++){
        	scanf("%d %c",&m,&d[i]);
            if(i<hn)	scanf("%d %d",&m,&m);
            if(i==hn){
            	if(odd)	scanf("%d",&m);
                else scanf("%d %d",&m,&m);
            }
        }
        printf("#%d ",t);
        dfs(1);
        putchar('\n');
    }
	return 0;
}
