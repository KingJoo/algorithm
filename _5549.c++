#include<cstdio>
#include<cstring>
char n[101];
int tc;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s",n);
        if((n[strlen(n)-1]-'0')%2)	printf("#%d Odd\n",t);
        else	printf("#%d Even\n",t);
    }
	return 0;
}
