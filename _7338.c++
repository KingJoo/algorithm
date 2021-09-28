#include<cstdio>
int tc,n,m;
long long y,k;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%ld%d",&y,&m);
        k=(y-2016)*12+m;
     	y=2016+k/13;
        m=k%13;
        if(m==0){
            y--;
            m=13;
        }
    	printf("#%d %ld %d\n",t,y,m);
    }
	return 0;
}
