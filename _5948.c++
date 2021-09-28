#include<cstdio>
#include<algorithm>
using namespace std;
int tc,a[7],b[35],cnt,idx;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	for(int i=0;i<7;i++)
        	scanf("%d",&a[i]);
        idx=0;
        for(int i=0;i<5;i++)
            for(int j=i+1;j<6;j++)
                for(int k=j+1;k<7;k++)
            		b[idx++]=a[i]+a[j]+a[k];
        sort(b,b+35);
        idx--;
        cnt=1;
        while(true){
            if(b[idx]!=b[idx-1])	cnt++;
            idx--;
            if(cnt==5)	break;
        }
        printf("#%d %d\n",t,b[idx]);
    }
    return 0;
}
