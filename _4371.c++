#include<cstdio>
#include<cstring>
int tc,n,cnt,d[5000],gap,nm;
bool ck[5000];
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&d[i]);
        for(int i=1;i<n;i++){
            if(!ck[i]){
                gap=d[i]-d[0];
                nm=d[0]%gap;
            	ck[i]=true;
                cnt++;
                for(int j=i+1;j<n;j++)
                	if(!ck[j]&&d[j]%gap==nm)	ck[j]=true;
            }
        }
        memset(ck,false,sizeof(ck));
        printf("#%d %d\n",t,cnt);
    }
	return 0;
}
