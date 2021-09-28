#include<cstdio>
#include<algorithm>
int tc,n,r,tmp;
typedef struct{int t,d;}td;
td a[1000000];
bool cmp(td a,td b){return a.d<b.d;}
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++)
        	scanf("%d%d",&a[i].t,&a[i].d);
        std::sort(a,a+n,cmp);
        r=a[0].d-a[0].t;
        for(int i=1;i<n;i++){
        	if(r==0)	break;
            a[i].t+=a[i-1].t;
            tmp=a[i].d-a[i].t;
            if(tmp<r)	r=tmp;
        }
        printf("#%d %d\n",t,r);
    }
    return 0;
}
