#include<cstdio>
#include<cstring>
int tc,l,n,h,p;
char a[1002];

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s",a);
        l=strlen(a);
        n=a[0]-'0';
        p=0;
        for(int i=1;i<l;i++){
       		if(a[i]=='0')	continue;
            h=a[i]-'0';
            if(n<i)	{
            	p+=(i-n);
                n+=(h+i-n);
            }
            else	n+=h;
        }
        printf("#%d %d\n",t,p);
    }
	return 0;
}
