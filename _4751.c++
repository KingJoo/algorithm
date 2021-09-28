#include<cstdio>
#include<cstring>
int tc,l,ss;
char p[5][201], s[51];

int main(){
	scanf("%d",&tc);

    //init
    for(int i=0;i<201;i++){
    	if(i%4==2)	p[0][i]=p[4][i]='#';
        else	p[0][i]=p[4][i]='.';
        if(i%2)	p[1][i]=p[3][i]='#';
        else	p[1][i]=p[3][i]='.';
        if(i%4)	p[2][i]='.';
        else	p[2][i]='#';
    }

    for(int t=1;t<=tc;t++){
    	scanf("%s",s);
        l=strlen(s);
        ss=2;
        for(int i=0;i<l;i++){
        	p[2][ss]=s[i];
            ss+=4;
        }
        l<<=2;
        l++;
        for(int i=0;i<5;i++){
        	for(int j=0;j<l;j++)
                putchar(p[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
