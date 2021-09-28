#include<cstdio>
bool ck[1000],k;
int tc,n,c,v[1000],r;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        c=0;
        for(int i=1;i<=n;i++){
        	scanf("%d",&v[i]);
            v[i]%=3;
            if(v[i]==i%3)	ck[i]=1;
        }
        for(int i=1;i<n;i++){
        	if(!ck[i]){
                k=0;
                r=i%3;
            	for(int j=i+1;j<=n;j++)
                	if(!ck[j]&&v[j]==r&&v[i]==j%3){
                        ck[j]=k=1;
                        break;
                    }
                if(!k)
                    for(int j=i+1;j<=n;j++)
                    	if(!ck[j]&&v[j]==r){
                        	v[j]=v[i];
                            break;
                        }
                c++;
            }
        }
        for(int i=1;i<=n;i++)
            ck[i]=0;
    	printf("#%d %d\n",t,c);
    }
	return 0;
}
