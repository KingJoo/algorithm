#include<cstdio>
int tc,n,a[100000],c;
bool z,u;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        c=z=1;
        for(int i=1;i<n;i++){
            if(z){
                if(a[i-1]==a[i])	continue;
            	else if(a[i-1]<a[i])	u=1;
                else	u=0;
                z=0;
            }
            else{
            	if(u){
                	if(a[i-1]>a[i]){
                		z=1;	c++;
                	}
                }
                else{
                	if(a[i-1]<a[i]){
                		z=1;	c++;
                	}
                }
            }
        }
        printf("#%d %d\n",t,c);
    }
	return 0;
}
