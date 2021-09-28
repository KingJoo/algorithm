#include<stdio.h>
#include<string.h>
int n,a;
char s[101];

int main(){
    scanf("%d",&n);
    for(int t=1;t<=n;t++){
        a=0;
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
            a^=(1<<(s[i]-'a'));
        printf("#%d ",t);
        if(a!=0){
            for(int i=0;i<26;i++){
                if(a&1)	putchar('a'+i);
            	a>>=1;
        	}
        }
        else 	printf("Good");
        putchar('\n');
    }
	return 0;
}
