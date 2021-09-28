#include<cstdio>
int n[8],s;
bool brk;
int main(){
	for(int t=1;t<=10;t++){
    	scanf("%d",&s);
        for(int i=0;i<8;i++)
            scanf("%d",&n[i]);
        s=0;	brk=false;
        while(true){
            for(int i=1;i<=5;i++){
            	s%=8;
            	n[s]-=i;
                s++;
            	if(n[s-1]<=0){brk=true;	break;}
            }
            if(brk)	break;
        }
        printf("#%d ",t);
        for(int i=0;i<7;i++)
            printf("%d ",n[(s+i)%8]);
        printf("0\n");
    }
	return 0;
}
