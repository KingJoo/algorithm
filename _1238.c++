#include<iostream>
#include<queue>
using namespace std;
bool ck[101],call[101][101];
int n,s,a,b,tp,mx,size;
queue<int> q;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d%d",&n,&s);
        n>>=1;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            call[a][b]=1;
        }
        mx=0;
        q.push(s);
        ck[s]=1;
        size=q.size();
        while(size){
        	tp=q.front();
            q.pop();	size--;
            mx=mx>tp?mx:tp;
            for(int i=1;i<=100;i++)
            	if(call[tp][i]&&!ck[i]){
                    q.push(i);
                    ck[i]=1;
                }
            if(size==0){
            	size=q.size();
                if(size!=0)	mx=0;
            }
        }
        for(int i=1;i<=100;i++){
        	ck[i]=0;
            for(int j=1;j<=100;j++)
                call[i][j]=0;
        }
        printf("#%d %d\n",t,mx);
    }
	return 0;
}
