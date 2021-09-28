#include<cstdio>
int tbl[100][100],n,cnt;

int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++)
                scanf("%d",&tbl[i][j]);
        }
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //n극 아래로
                if(tbl[j][i]==1){
                    for(int k=j;k<n;k++){
                        if(tbl[k][i]==2){
                            cnt++;
                            tbl[k][i]=3;
                            j=k;
                            break;
                        }
                    }
                }
                //s극 위로
                else if(tbl[j][i]==2){
                    for(int k=j;k>=0;k--){
                        if(tbl[k][i]==1){
                            cnt++;
                            tbl[k][i]=3;
                            break;
                        }
                        else if(tbl[k][i]==3)	break;
                    }
                }
            }
        }
        printf("#%d %d\n",t,cnt);
    }
	return 0;
}
