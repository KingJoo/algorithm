#include<cstdio>
int tc,n,cnt;
char s[100001],s1[100001],c;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	cnt=0;
        scanf("%d %s %s",&n,s,s1);
        for(int i=0;i<n;i++)
            if(s[i]==s1[i])	cnt++;
    	printf("#%d %d\n",t,cnt);
    }
	return 0;
}
