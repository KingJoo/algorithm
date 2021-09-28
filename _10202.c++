#include<cstdio>
char s[3][1001];
int T,n,r;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%d",&n);
        scanf("%s%s%s",s[0],s[1],s[2]);
        r=0;
        for(int i=0;i<n;i++){
        	if(s[0][i]==s[1][i]){
            	if(s[1][i]!=s[2][i])	r++;
            }
            else{
            	if(s[1][i]==s[2][i]||s[0][i]==s[2][i])	r++;
                else r+=2;
            }
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
