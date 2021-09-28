#include<cstdio>
char s[5];
int T,n,f,r;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%s",s);
        f=(s[0]-'0')*10+s[1]-'0';
        r=(s[2]-'0')*10+s[3]-'0';
        printf("#%d ",t);
        if(f==0||f>12){
            if(r==0||r>12)	printf("NA");
            else	printf("YYMM");
        }
        else{
            if(r==0||r>12)	printf("MMYY");
            else	printf("AMBIGUOUS");
        }
        putchar('\n');
    }
    return 0;
}
