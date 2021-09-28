#include<cstdio>
int tc;
char c;
int main(){
	scanf("%d ",&tc);
    for(int t=1;t<=tc;t++){
    	printf("#%d ",t);
        while(true){
            c=getchar();
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')	continue;
        	if(c=='\n'||c==EOF)	break;
            putchar(c);
        }
        putchar('\n');
    }
	return 0;
}
