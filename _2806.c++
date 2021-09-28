#include<cstdio>
#include<cstring>
int tc,n,cnt,q[11];

bool chk(int y, int x){
    for(int i=1;i<y;i++)
        if((x-i>0&&q[y-i]==x-i)||(x+i<n&&q[y-i]==x+i)||q[i]==x)	return false;
    return true;
}

void dfs(int l){
	if(l==n){
        cnt++;
        return;
    }
    for(int i=1;i<n;i++)
    	if(chk(l,i)){
            q[l]=i;
            dfs(l+1);
        }
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        n++;
        cnt=0;
        memset(q,0,sizeof(q));
        dfs(1);
        printf("#%d %d\n",t,cnt);
    }
    return 0;
}
