#include<cstdio>
int T,n,q,a[300000],m;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d%d%d",&n,&q,&m);
        a[0]=m;
        for(int i=1;i<n;i++){
        	scanf("%d",&a[i]);
            if(a[i]>m)	a[i]=m;
        	else if(a[i]<m)	m=a[i];
        }
        while(q--){
        	n--;
            scanf("%d",&m);
            if(n<0){while(q--) scanf("%d",&m);	break;}
            while(n>=0&&a[n]<m)	n--;
        }
        printf("#%d %d\n",t,++n);
    }
    return 0;
}
