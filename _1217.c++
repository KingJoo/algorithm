#include<cstdio>
int n,m,r;

void nth(int d){
	if(d==m)	return;
    r*=n;
    nth(d+1);
}

int main(){
	for(int t=1;t<=10;t++){
        scanf("%d %d %d",&r,&n,&m);
        r=1;
        nth(0);
        printf("#%d %d\n",t,r);
    }
    return 0;
}
