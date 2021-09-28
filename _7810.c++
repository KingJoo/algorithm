#include<cstdio>
#include<algorithm>
int tc,n,h,s,arr[500000];

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        std::sort(arr,arr+n);
        s=0;h=1;
        while(1){
            while(s<n&&arr[s]<h)	s++;
            if(n==s||n-s<h)	break;
            h++;
        }
        printf("#%d %d\n",t,h-1);
    }
}
