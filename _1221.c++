#include<cstdio>
#include<cstring>
char tmp[4], r[][4]={"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
int tc,n,num[10];

int main(){
	scanf("%d",&tc);
    for(int t=0;t<tc;t++){
    	memset(num,0,sizeof(num));
        scanf("%s",tmp);
        printf("%s\n",tmp);
        scanf("%d",&n);
        while(n--){
        	scanf("%s",tmp);
            if(tmp[0]=='Z')	num[0]++;
            else if(tmp[0]=='O')	num[1]++;
            else if(tmp[0]=='T'){
            	if(tmp[1]=='W')	num[2]++;
                else	num[3]++;
            }
            else if(tmp[0]=='F'){
            	if(tmp[1]=='O')	num[4]++;
                else	num[5]++;
            }
            else if(tmp[0]=='S'){
            	if(tmp[1]=='I')	num[6]++;
                else	num[7]++;
            }
            else if(tmp[0]=='E')	num[8]++;
            else	num[9]++;
        }
        for(int i=0;i<10;i++)
            while(num[i]--)
            	printf("%s ",r[i]);
        putchar('\n');
    }
    return 0;
}
