#include<cstdio>
#include<cstring>

int main(){
	int tc;
    char s[21], r1[]="Not exist",r2[]="Exist";
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	char * r=r2;
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<(l>>1);i++){
        	if(s[i]!=s[l-1-i]){
                if(s[i]=='?'||s[l-1-i]=='?')	continue;
            	else{
                    r=r1;
                	break;
                }
            }
        }
        printf("#%d %s\n",t,r);
    }
	return 0;
}
