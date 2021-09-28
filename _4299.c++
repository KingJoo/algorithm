#include<cstdio>
int tc,d,h,m,r;
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d %d %d",&d,&h,&m);
        m-=11;
        if(m<0){
            m+=60;
            h--;
        }
        h-=11;
        if(h<0){
        	h+=24;
            d--;
        }
        d-=11;
        if(d<0)	r=-1;
        else	r=d*24*60+h*60+m;
        printf("#%d %d\n",t,r);
    }
	return 0;
}
