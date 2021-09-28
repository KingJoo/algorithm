#include<cstdio>
#include<cstring>
int n,a,b;
char pw[101];

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d %s",&n,pw);
        a=0;	b=1;
        while(b<n){
            if(pw[a]!=pw[b]){
                a=b;	b++;
            }
            else{
                pw[a]=pw[b]='x';
                a--;	b++;
                while(a>=0){
                    if(pw[a]=='x')	a--;
                    else	break;
                }
                if(a<0){
                    a=b;	b++;
                }
            }
        }
        printf("#%d ",t);
        for(int i=0;i<n;i++)
            if(pw[i]!='x')	putchar(pw[i]);
        putchar('\n');
    }
	return 0;
}
