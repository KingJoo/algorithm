#include<cstdio>
#define Max(a,b) a>b?a:b
int L;
char s[100][101];
bool ck;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&L);	L=0;
        for(int i=0;i<100;i++)
            scanf("%s",s[i]);
        for(int i=0;i<=99;i++){
        	for(int j=0;j<=99;j++){
            	if(99-j<L)	break;
                for(int k=99;k>=j;k--){
                    ck=true;
                	for(int l=0;l<=(k-j)/2;l++){
                    	if(s[i][j+l]!=s[i][k-l]){
                            ck=false;
                            break;
                        }
                    }
                    if(ck)	L=Max(k-j,L);
                    ck=true;
                	for(int l=0;l<=(k-j)/2;l++){
                    	if(s[j+l][i]!=s[k-l][i]){
                            ck=false;
                            break;
                        }
                    }
                    if(ck)	L=Max(k-j,L);
                }
            }
        }
        printf("#%d %d\n",t,L+1);
    }
	return 0;
}
