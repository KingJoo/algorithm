#include<cstdio>
#include<cstring>
char a[1001],T[51],d[][6]={"yotta","zetta","exa","peta","tera","giga","mega","kilo","hecto","deca","deci","centi","milli","micro","nano","pico","femto","ato","zepto","yocto"};
int tc,n,z,g,di,ui,al,l[]={24,21,18,15,12,9,6,3,2,1,-1,-2,-3,-6,-9,-12,-15,-18,-21,-24};

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%s%s",a,T);
        z=0;
        for(int i=0;i<20;i++){
        	if(strcmp(T,d[i])==0){
            	z=l[i];
                scanf("%s",T);
                break;
            }
        }
        al=strlen(a);
        di=0;
        for(int i=1;i<al;i++)
            if(a[i]=='.'){
            	di=i;
                break;
            }
        for(int i=0;i<al;i++)
            if(a[i]>'0'&&a[i]!='.'){
                ui=i;
                break;
            }
        if(di==0)
            z+=(al-1);
        else{
        	g=di-ui;
        	z+=g;
        	if(g>0)	z--;
        }
        printf("#%d ",t);
        putchar(a[ui]);
        if(ui!=al-1)	putchar('.');
        for(int i=ui+1;i<al;i++)
            if(a[i]!='.')	putchar(a[i]);
        printf(" * 10^%d %s\n",z,T);
    }
	return 0;
}
