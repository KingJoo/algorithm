#include<cstdio>
#include<algorithm>
int tc,n,m,c1,c2,c[500000],h,mn,idx,tp;

int bs(int s,int e){
	if(s>e)	return e;
    int m=(s+e)>>1;
    if(c[m]<h)	bs(m+1,e);
    else if(c[m]==h)	return m;
    else bs(s,m-1);
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d%d%d%d",&n,&m,&c1,&c2);
        mn=0x7fffffff;
        c1-=c2;
        if(c1<0)	c1=-c1;
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        std::sort(c,c+n);
        for(int i=0;i<m;i++){
        	scanf("%d",&h);
            idx=bs(0,n-1);
            for(int j=idx;j>=0;j--){
            	tp=c[j]-h;
                if(tp<0)	tp=-tp;
                if(tp>mn)	break;
                else if(tp==mn)	c2++;
                else{
                    mn=tp;
                	c2=1;
                }
            }
            for(int j=idx+1;j<n;j++){
            	tp=c[j]-h;
                if(tp<0)	tp=-tp;
                if(tp>mn)	break;
                else if(tp==mn)	c2++;
                else{
                    mn=tp;
                	c2=1;
                }
            }
        }
        printf("#%d %d %d\n",t,c1+mn,c2);
    }
    return 0;
}
