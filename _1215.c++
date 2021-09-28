#include<cstdio>
#include<cstring>
int	n,cnt;
char c[8][9];
bool ck;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&n);
        for(int i=0;i<8;i++)
        	scanf("%s",c[i]);
    	cnt=0;
        for(int i=0;i<8;i++){
        	for(int j=0;j<=8-n;j++){
            	ck=true;
                for(int k=0;k<n/2;k++){
                    if(c[i][j+k]!=c[i][j+n-1-k]){
                    	ck=false;
                        break;
                    }
                }
                if(ck)	cnt++;
            }
        }
        for(int j=0;j<8;j++){
        	for(int i=0;i<=8-n;i++){
            	ck=true;
                for(int k=0;k<n/2;k++){
                    if(c[i+k][j]!=c[i+n-1-k][j]){
                    	ck=false;
                        break;
                    }
                }
                if(ck)	cnt++;
            }
        }
        printf("#%d %d\n",t,cnt);
    }
	return 0;
}
