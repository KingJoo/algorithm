#include<cstdio>
char c[1000][81];
int main(){
	int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc;t++){
    	int n;
        scanf("%d",&n);
		for(int i=0;i<n;i++)
            scanf("%s",c[i]);
        printf("#%d ",t);
        int m=n/2;
        if(n%2){
            for(int i=0;i<m;i++)
            	printf("%s %s ",c[i],c[i+m+1]);
            printf("%s\n",c[m]);
        }
        else{
        	for(int i=0;i<m;i++)
            	printf("%s %s ",c[i],c[i+m]);
            putchar('\n');
        }
    }
	return 0;
}
