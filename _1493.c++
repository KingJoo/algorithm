#include<cstdio>
int tc,p,q,r,x,y;

void nToP(int n){
	int i,s,a;
    i=1;	s=0;
    while(true){
        s+=i;
        if(s<n)	i++;
        else	break;
    }
    a=s-n;
    x+=1+a;
    y+=i-a;
    return;
}

void pToN(){
    for(int i=1;i<x+y;i++)
        r+=i;
    r-=x-1;
    return;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	r=x=y=0;
        scanf("%d %d",&p,&q);
      	nToP(p);
        nToP(q);
        pToN();
    	printf("#%d %d\n",t,r);
    }
	return 0;
}
