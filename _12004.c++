#include <cstdio>
int N,a;
bool yes;

int main(){
	scanf("%d",&N);
    for(int i=1;i<=N;i++){
    	scanf("%d",&a);
        yes=false;
        for(int j=9;j>0;j--){
        	if(a/j<10&&a/j>0&&a%j==0){
            	yes=true;
                break;
            }
        }
        printf("#%d",i);
        if(yes)	printf(" Yes\n");
        else printf(" No\n");
    }
    return 0;
}
