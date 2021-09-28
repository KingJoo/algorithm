#include<cstdio>
int tc;
double p,q;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%lf%lf",&p,&q);
        printf("#%d ",t);
        if(1<p*(2-q))	printf("YES\n");
        else	printf("NO\n");
    }
	return 0;
}
