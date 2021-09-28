#include<cstdio>
#include<cstring>
char s[101];
int tc,n,c,ss[15];

void dfs(int N,int a){
    if(N==n){
    	if(0x3ffffff==a)	c++;
        return;
    }
    dfs(N+1,a);
    dfs(N+1,a|ss[N]);
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            c=0;
            for(int j=0;j<strlen(s);j++)
            	c|=(1<<(s[j]-'a'));
            ss[i]=c;
        }
        c=0;
        dfs(0,0);
        printf("#%d %d\n",t,c);
    }
	return 0;
}
