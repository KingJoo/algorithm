#include<cstdio>
#include<cstring>
int tc;
long long n;
bool ck[10];

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%lld",&n);
        bool brk=false;
        while(n>1){
        	if(n%2==0)	n>>=1;
            else{
                n=3*n+3;
                if(!ck[n%10])	ck[n%10]=true;
                else {
                    brk=true;
                    break;
                }
            }
        }
        printf("#%d ",t);
        if(brk)	printf("NO\n");
        else	printf("YES\n");
        memset(ck,false,sizeof(ck));
    }
	return 0;
}
