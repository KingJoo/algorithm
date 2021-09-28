#include<cstdio>
#include<cstring>
char s1[11],s2[1001];
int	cnt,l1,l2;
bool ck;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&cnt);	cnt=0;
        scanf("%s %s",s1,s2);
        l1=strlen(s1);
        l2=strlen(s2);
        for(int i=0;i<=l2-l1;i++){
        	if(s1[0]==s2[i]){
                ck=true;
                for(int j=0;j<l1;j++){
                	if(s1[0+j]!=s2[i+j]){
                        ck=false;
                        break;
                    }
                }
                if(ck)	cnt++;
            }
        }
    	printf("#%d %d\n",t,cnt);
    }
	return 0;
}
