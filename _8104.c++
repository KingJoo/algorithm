#include<cstdio>
int tc,n,k,res;
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %d",&n,&k);
    	printf("#%d ",t);
        if(n%2){
            n--;
        	res=((n*k+1)*n)/2+(n*k+1);
            for(int i=0;i<k;i++){
                printf("%d ",res);
                res++;
            }
        }
        else{
            res=((n*k+1)*n)/2;
        	for(int i=0;i<k;i++)
                printf("%d ",res);
        }
        putchar('\n');
    }
	return 0;
}
