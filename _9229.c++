#include<cstdio>
#include<iostream>
#include<algorithm>
int tc,n,m,mx,tmp;
int nn[1000];

int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        	scanf("%d",&nn[i]);
        std::sort(nn,nn+n);
        mx=nn[0]+nn[1];
        if(mx>m)	mx=-1;
        else if(mx<m){
        	bool pass=false;
            for(int i=n-1;i>0;i--){
                if(pass)	break;
                for(int j=0;j<i;j++){
                	tmp=nn[i]+nn[j];
                    if(tmp>m)	break;
                    else if(tmp==m){
                       	mx=m;
                        pass=true;
                       	break;
                    }
                    if(tmp>mx)	mx=tmp;
                }
            }
        }
        printf("#%d %d\n",t,mx);
    }
	return 0;
}
