#include<cstdio>
int tc,n,s;
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	s=0;
        for(int i=0;i<5;i++){
            scanf("%d",&n);
        	if(n<40)	s+=40;
            else	s+=n;
        }
        printf("#%d %d\n",t,s/5);
    }
    return 0;
}
