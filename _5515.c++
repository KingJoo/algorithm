#include<cstdio>
int tc,m,d,td,mon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&m,&d);
        td=d+3;
        for(int i=1;i<m;i++)
            td+=mon[i];
        td%=7;
        printf("#%d %d\n",t,td);
    }
	return 0;
}
