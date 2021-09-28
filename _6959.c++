#include<cstdio>
#include<cstring>
int tc,l,si;
char str[1001];
bool aW;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s",str);
        l=strlen(str);
        si=0;
        aW=false;
        if(l!=1){
        	while(si<l-1){
            	int tmp=(str[si]-'0')+(str[si+1]-'0');
                if(tmp<10){
                	si++;
                    str[si]=tmp+'0';
                }
                else{
                	str[si]=1+'0';
                    str[si+1]=tmp-10+'0';
                }
            	aW=!aW;
            }
        }
        printf("#%d ",t);
        if(aW)	putchar('A');
        else	putchar('B');
        putchar('\n');
    }
	return 0;
}
