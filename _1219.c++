#include<cstdio>
int n,N,a,b,m[100][2],r;
bool ck[100];

void reset(){
	for(int i=0;i<100;i++){
    	m[i][0]=m[i][1]=-1;
        ck[i]=0;
    }
    r=0;
    return;
}

void dfs(int idx){
	if(r||idx==-1||ck[idx])	return;
    if(idx==99){
        r=1;
        return;
    }
    ck[idx]=1;
    dfs(m[idx][0]);
    dfs(m[idx][1]);
    ck[idx]=0;
}

int main(){
	for(int t=1;t<=10;t++){
    	reset();
        scanf("%d %d",&n,&N);
        for(int i=0;i<N;i++){
        	scanf("%d%d",&a,&b);
            if(m[a][0]==-1)	m[a][0]=b;
            else m[a][1]=b;
        }
        dfs(0);
        printf("#%d %d\n",t,r);
    }
	return 0;
}
