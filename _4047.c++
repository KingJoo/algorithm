#include<cstdio>
#include<cstring>
int tc,num[4],l,m,n;
char str[3001];
bool cd[4][14],err;
int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s",str);
    	memset(cd,false,sizeof(cd));
        err=false;
        num[0]=num[1]=num[2]=num[3]=13;
        l=strlen(str);
        for(int i=0;i<l;i+=3){
            n=(str[i+1]-'0')*10+str[i+2]-'0';
            if(str[i]=='S')	m=0;
            else if(str[i]=='D')	m=1;
            else if(str[i]=='H')	m=2;
            else	m=3;
            if(cd[m][n]){
                err=true;
                break;
            }
            cd[m][n]=true;
            num[m]--;
        }
        printf("#%d ",t);
        if(err)	printf("ERROR\n");
        else printf("%d %d %d %d\n",num[0],num[1],num[2],num[3]);
    }
    return 0;
}
