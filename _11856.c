#include <stdio.h>
int n,c;
char s[5], x;

int main(){
    scanf("%d",&n);
    for(int t=1;t<=n;t++){
		scanf("%s",s);
        c=0;x=s[0];
        for(int i=1;i<4;i++){
            x^=s[i];
            if(s[0]==s[i])	c++;
        }
        x==0&&c==1?printf("#%d Yes\n",t):printf("#%d No\n",t);
    }
    return 0;
}
