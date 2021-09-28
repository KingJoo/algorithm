#include<cstdio>
#include<cstring>
char s[1001],S[1001],T;
int tc,n,c,l;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s%d",s,&n);
        l=strlen(s);
        c=0;
        for(int i=0;i<n;i++){
        	scanf("%s",S);
            if(l==strlen(S)){
            	T=1;
                for(int j=0;j<l;j++){
                    if((s[j]=='2'&&(S[j]>'c'))||
                       (s[j]=='3'&&(S[j]<'d'||S[j]>'f'))||
                       (s[j]=='4'&&(S[j]<'g'||S[j]>'i'))||
                       (s[j]=='5'&&(S[j]<'j'||S[j]>'l'))||
                       (s[j]=='6'&&(S[j]<'m'||S[j]>'o'))||
                       (s[j]=='7'&&(S[j]<'p'||S[j]>'s'))||
                       (s[j]=='8'&&(S[j]<'t'||S[j]>'v'))||
                       (s[j]=='9'&&(S[j]<'w'))){T=0;break;}
                }
                if(T)	c++;
            }
        }
        printf("#%d %d\n",t,c);
    }
	return 0;
}
