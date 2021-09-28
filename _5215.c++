#include<cstdio>
int tc,n,l,mx,mk[20][2],tmp;
bool ck[20];

void dfs(int pre, int m, int k){
    if(k>l){
        mx=mx>m-mk[pre][0]?mx:m-mk[pre][0];
        return;
    }
    if(k==l||pre==n-1){
        mx=mx>m?mx:m;
    	return;
    }
    for(int i=pre+1;i<n;i++){
    	if(!ck[i]){
        	ck[i]=true;
            dfs(i,m+mk[i][0],k+mk[i][1]);
            ck[i]=false;
        }
    }
}

int main() {
	scanf("%d",&tc);
	for (int t=1;t<=tc;t++) {
		scanf("%d %d",&n,&l);
		for (int i=0;i<n;i++)
			scanf("%d %d",&mk[i][0],&mk[i][1]);
		mx=0;
        dfs(-1,0,0);
		printf("#%d %d\n",t,mx);
	}
	return 0;
}
