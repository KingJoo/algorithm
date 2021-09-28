#include<cstdio>
int s1,s2,a[100][100],mx;
int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&s1);
        for(int i=0;i<100;i++)
        	for(int j=0;j<100;j++)
            	scanf("%d",&a[i][j]);
        mx=0;
        for(int i=0;i<100;i++){
        	s1=s2=0;
            for(int j=0;j<100;j++){
                s1+=a[i][j];
                s2+=a[j][i];
            }
            mx=mx>s1?mx:s1;
            mx=mx>s2?mx:s2;
        }
        s1=s2=0;
        for(int i=0;i<100;i++){
        	s1+=a[i][i];
            s2+=a[i][99-i];
        }
        mx=mx>s1?mx:s1;
        mx=mx>s2?mx:s2;
        printf("#%d %d\n",t,mx);
    }
    return 0;
}
