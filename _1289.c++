#include<cstdio>
#include<cstring>
int tc,r,l;
char s[51];
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s",s);
        l=strlen(s)-1;
        r=0;
        if(s[0]=='1')	r++;
        for(int i=0;i<l;i++)
        	if(s[i]!=s[i+1])	r++;
        printf("#%d %d\n",t,r);
    }
    return 0;
}

