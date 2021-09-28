#include<cstdio>
#include<cstring>
int tc;
char str[5][16];
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	for(int i=0;i<5;i++){
        	scanf("%s",str[i]);
            for(int j=strlen(str[i]);j<15;j++)
            	str[i][j]=' ';
        }
        printf("#%d ",t);
        for(int i=0;i<15;i++)
        	for(int j=0;j<5;j++)
            	if(str[j][i]!=' ')	putchar(str[j][i]);
    	putchar('\n');
    }
	return 0;
}
