#include<cstdio>
#include<cstring>
int dn,h[101],n,mnH,mxH;

int main(){
    for(int t=1;t<=10;t++){
    	memset(h,0,sizeof(h));
        scanf("%d",&dn);
        for(int i=0;i<100;i++){
            scanf("%d",&n);
        	h[n]++;
        }
        for(int i=0;i<=100;i++){
        	if(h[i]){
                mnH=i;
                break;
            }
        }
        for(int i=100;i>0;i--){
        	if(h[i]){
                mxH=i;
                break;
            }
        }
        while(dn--){
        	if(mnH==mxH)	break;
            else if(mnH==mxH-1){
            	if(h[mnH]==h[mxH])	mxH--;
                break;
            }
            else{
            	h[mnH]--;	h[mnH+1]++;	h[mxH]--;	h[mxH-1]++;
                if(h[mnH]==0)	mnH++;
                if(h[mxH]==0)	mxH--;
            }
        }
        printf("#%d %d\n",t,mxH-mnH);
    }
	return 0;
}
