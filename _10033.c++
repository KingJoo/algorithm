#include<cstdio>
#include<cstring>
char s[200001];
int T,l,w;
long long r;

int main(){
	scanf("%d",&T);
    for(int t=1;t<=T;t++){
    	scanf("%s",s);
        r=w=0;
        l=strlen(s);
		while(l){
            l--;
        	if(s[l]=='B')	r+=w;
            else	w++;
        }
        printf("#%d %ld\n",t,r);
    }
    return 0;
}
