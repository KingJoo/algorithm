#include<cstdio>
int tc,n,h,r,a;
char c[50][50];
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&n);
        r=a=0;	h=n>>1;
        for(int i=0;i<n;i++){
        	scanf("%s",c[i]);
            if(i<h){
                for(int j=h-a;j<=h+a;j++)
            		r+=c[i][j]-'0';
                a++;
            }
            else{
                for(int j=h-a;j<=h+a;j++)
            		r+=c[i][j]-'0';
                a--;
            }
        }
    	printf("#%d %d\n",t,r);
    }
	return 0;
}
