#include <cstdio>
#include <cstring>
int v[1000001],tc,q,m;
long long s,p;

int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d%d%d",&s,&p,&q,&m);
        int i=1;
        v[s]=i;
        while(i++){
        	if(v[(p*s+q)%m]!=0){
                printf("#%d %d\n",t,i-v[(p*s+q)%m]);
                memset(v,0,sizeof(v));
            	break;
            }
            else{
                s=(p*s+q)%m;
            	v[s]=i;
            }
        }
    }
	return 0;
}
