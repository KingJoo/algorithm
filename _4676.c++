#include<cstdio>
#include<cstring>
int tc,n,l,tmp,loc[21];
char s[21];
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s %d",s,&n);
        l=strlen(s);
        for(int i=0;i<n;i++){
        	scanf("%d",&tmp);
            loc[tmp]++;
        }
        printf("#%d ",t);
    	for(int i=0;i<l;i++){
        	while(loc[i]){
                putchar('-');
                loc[i]--;
            }
            putchar(s[i]);
        }
        while(loc[l]){
                putchar('-');
                loc[l]--;
        }
        putchar('\n');
    }
	return 0;
}
