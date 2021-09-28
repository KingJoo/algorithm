#include<cstdio>
int tc;
long long n,a,b,r;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d%d%d",&n,&a,&b);
        r=0;
        if(a==b)	r++;
        else if(a<b){
        	if(n==2)	r++;
            else if(n>2)	r=(n-2)*(b-a)+1;
        }
        printf("#%d %ld\n",t,r);
    }
	return 0;
}
