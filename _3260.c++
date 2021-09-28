#include<cstdio>
#include<cstring>
int tc,al,bl,ll,sl,sum;
char a[103],b[103];
char * l, * s;
bool ov;

int ctoi(char a){return a-'0';}
char itoc(int a){return a+'0';}
int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%s %s",a,b);
        al=strlen(a)-1;
        bl=strlen(b)-1;
        ov=false;
        if(al>bl){
            l=a;	s=b;
            ll=al;	sl=bl;
        }
        else{
        	l=b;	s=a;
            ll=bl;	sl=al;
        }
        for(int i=ll;i>=0;i--){
			if(sl>=0){
                sum=ctoi(l[i])+ctoi(s[sl--]);
                if(ov)	sum++;
                if(sum>9){
                	ov=true;
                    l[i]=itoc(sum-10);
                }
                else{
                	ov=false;
                    l[i]=itoc(sum);
                }
            }
            else{
                sum=ctoi(l[i]);
                if(ov)	sum++;
            	if(sum>9){
                	ov=true;
                    l[i]=itoc(sum-10);
                }
                else{
                	ov=false;
                    l[i]=itoc(sum);
                }
            }
        }
        printf("#%d ",t);
        if(ov)	putchar('1');
        printf("%s\n",l);
    }
    return 0;
}

