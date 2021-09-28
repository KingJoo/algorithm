#include<cstdio>
#include<cstring>
int tc,n,d[1000],r;
bool ck[1000];

int seek(){
	for(int i=0;i<1000;i++)
        if(!ck[i])	return i;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&d[i]);
        memset(ck,false,sizeof(ck));
        for(int i=0;i<n;i++)
        	if(!ck[d[i]])	ck[d[i]]=true;
        r=seek();
        if(r==10){
        	for(int i=0;i<n-1;i++)
        		if(!ck[d[i]*10+d[i+1]])	ck[d[i]*10+d[i+1]]=true;
            r=seek();
            if(r==100){
                for(int i=0;i<n-2;i++)
        			if(!ck[d[i]*100+d[i+1]*10+d[i+2]])	ck[d[i]*100+d[i+1]*10+d[i+2]]=true;
                printf("#%d %d\n",t,seek());
            }
            else	printf("#%d %d\n",t,r);
        }
        else	printf("#%d %d\n",t,r);
    }
	return 0;
}
