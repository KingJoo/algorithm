#include<cstdio>
#include<cstring>
int tc,l;
char str[131];
bool f;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s",str);
        l=strlen(str);
        f=0;
        for(int i=0;i<l;){
        	if(str[i++]!='F')	break;
            else{
                if(i==l)	break;
                else{
                	if(str[i]=='F'){
                    	while(i+1<l&&str[i+1]=='F')	i++;	i++;
                        if(i+2>=l)	break;
                        if(str[i++]!='M')	break;
                        if(str[i++]!='C')	break;
                        while(i<l&&str[i]=='M')	i++;
                        if(i==l)	f=1;
                    }
                    else if(str[i]=='C'){
                    	while(i+1<l&&str[i+1]=='C')	i++;	i++;
                        if(i+1>=l)	break;
                        if(str[i++]!='M')	break;
                        if(str[i++]!='F')	break;
                        if(i==l)	f=1;
                    }
                    else	break;
                }
            }
        }
        printf("#%d ",t);
        if(f)	printf("DETECTED!\n");
        else	printf("NOTHING!\n");
    }
	return 0;
}
