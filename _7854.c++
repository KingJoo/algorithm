#include<cstdio>
#include<cmath>
int tc,x,nn[100],tp,idx,c;
long long tn[10]={10,},ttn;

int main(){
    for(int i=1;i<10;i++)
        tn[i]=tn[i-1]*10;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        	tp=pow(2.0,i)*pow(5.0,j);
            for(int k=0;k<10;k++){
            	if(tp%tn[k]==tp){
                	ttn=tn[k];
                    break;
                }
            }
            c=1;
            for(int k=1;k<10;k++){
            	if((ttn+tp)%tp!=0){
                    c=0;
                    break;
                }
                ttn+=ttn;
            }
            if(c)	nn[idx++]=tp;
        }
    }
    scanf("%d",&tc);
	for(int t=1;t<=tc;t++){
        scanf("%d",&x);
        c=0;
        for(int i=0;i<idx;i++)
            if(nn[i]<=x)	c++;
        printf("#%d %d\n",t,c);
    }
    return 0;
}
