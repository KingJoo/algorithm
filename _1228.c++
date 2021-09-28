#include<cstdio>
#include<cstring>
int a[20],n,x,y,tmp;
char cmd[2];

int main(){
	for(int t=1;t<=10;t++){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
        	scanf("%s %d %d",cmd,&x,&y);
            for(int j=9;j>=x+y;j--)
                a[j]=a[j-y];
            for(int j=x;j<x+y;j++){
                scanf("%d",&tmp);
                if(j<=9)	a[j]=tmp;
            }
        }
        printf("#%d",t);
        for(int i=0;i<10;i++)
            printf(" %d",a[i]);
        putchar('\n');
    }
	return 0;
}
