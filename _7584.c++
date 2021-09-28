#include<cstdio>
long long _2[60],k=1;
int tc,r,idx;

int bs(int s,int e){
	if(s>e)	return e;
    if(k==_2[s])	return s;
    int m=(s+e)>>1;
    if(k>_2[m])	bs(m+1,e);
    else if(k<_2[m])	bs(s,m-1);
    else	return m;
}

int main(){
    for(int i=0;i<60;i++)
        _2[i]=(k<<i);

    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%ld",&k);
        r=0;	idx=59;
        while(k>2){
        	idx=bs(0,idx);
            k-=_2[idx];
            if(k==_2[idx-1]){r=1; break;}
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
