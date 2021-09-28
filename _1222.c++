#include<cstdio>
int n,r;
char a;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&n);
        r=0;
        getchar();
        for(int i=0;i<n;i++){
        	a=getchar();
            if(i%2)	continue;
            r+=(a-'0');
        }
        printf("#%d %d\n",t,r);
    }
    return 0;
}
