#include<cstdio>
int n,r,tmp;
char a;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&n);
        r=0;
        getchar();
        for(int i=0;i<n;i++){
        	a=getchar();
            if(i%2){
                if(a=='+'){
                	r+=tmp;
                	tmp=0;
                }
                else{
                    i++;
                    a=getchar();
                	tmp*=(a-'0');
                }
            }
            else	tmp=a-'0';
        }
        r+=tmp;
        printf("#%d %d\n",t,r);
    }
	return 0;
}
