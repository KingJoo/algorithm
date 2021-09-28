#include<cstdio>
#include<algorithm>
int tc,n,w[100],wc,c;
bool cmp(int a,int b){return a>b;}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        wc=c=0;
        for(int i=0;i<n;i++){
        	scanf("%d",&w[wc]);
            if(w[wc]<50)	wc++;
            else	c++;
        }
        std::sort(w,w+wc,cmp);
        for(int i=0;i<wc;i++){
            wc-=(50/w[i]);
            if(50%w[i]==0)	wc++;
            if(wc<=i)	break;
            c++;
        }
        printf("#%d %d\n",t,c);
    }
	return 0;
}
