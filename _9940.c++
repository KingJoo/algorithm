#include<cstdio>
#include<cstring>
bool ck[100001],y;
int T,n,a;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d",&n);
        y=1;
        printf("#%d ",t);
        while(n--){
        	scanf("%d",&a);
            if(ck[a]){
                y=0;
            	break;
            }
            else ck[a]=1;
        }
        if(y)	printf("Yes");
        else{
        	while(n--)	scanf("%d",&a);
            printf("No");
        }
        putchar('\n');
        memset(ck,0,sizeof(ck));
    }
	return 0;
}
