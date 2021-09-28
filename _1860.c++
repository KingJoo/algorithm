#include<cstdio>
#include<algorithm>
using namespace std;
int tc,n,m,k,nn[100];
bool possible;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&nn[i]);
        sort(nn,nn+n);
        possible=true;
        for(int i=0;i<n;i++){
            if(i+1>(nn[i]/m)*k){
            	possible=false;
                break;
            }
        }
        printf("#%d ",t);
        if(possible)	printf("Possible\n");
        else	printf("Impossible\n");
    }
	return 0;
}
