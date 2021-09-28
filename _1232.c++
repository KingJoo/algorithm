#include<cstdio>
int n,m,c[1001][2];
double r[1001];
char sym[1001],a;

int main(){
	for(int t=1;t<=10;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
        	scanf("%d %c",&m,&sym[i]);
            if(sym[i]<'0'||sym[i]>'9')
            	scanf("%d %d",&c[i][0],&c[i][1]);
            else{
            	m=sym[i]-'0';
                while(1){
                	a=getchar();
                    if(a<'0'||a>'9')	break;
                    m=m*10+a-'0';
                }
                r[i]=m;
            }
        }
        while(n){
        	if(sym[n]=='+'){r[n]=r[c[n][0]]+r[c[n][1]];}
            else if(sym[n]=='-'){r[n]=r[c[n][0]]-r[c[n][1]];}
            else if(sym[n]=='*'){r[n]=r[c[n][0]]*r[c[n][1]];}
            else if(sym[n]=='/'){r[n]=r[c[n][0]]/r[c[n][1]];}
            sym[n]=0;	n--;
        }
    	printf("#%d %d\n",t,(int)r[1]);
    }
	return 0;
}
