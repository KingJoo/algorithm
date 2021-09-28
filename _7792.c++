#include<cstdio>
#include<cstring>
#include<cstdlib>
typedef struct{
    int al;
    char nm[21];
}name;
int tc,n,c,cnt;
name a[100];
bool ck[26];
char z;

int cmp(const void* a,const void* b){
    if((*(name *)a).al!=(*(name *)b).al)	return	(*(name *)a).al<(*(name *)b).al;
    else	return	strcmp((*(name *)a).nm,(*(name *)b).nm);
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++){
        	c=0;
            while(1){
        		z=getchar();
                if(z=='\n'||z==EOF){
                    a[i].nm[c]=0;
                    cnt=0;
                    for(int i=0;i<26;i++){
                    	if(ck[i]){
                        	cnt++;
                            ck[i]=0;
                        }
                    }
                    a[i].al=cnt;
                    break;
                }
                a[i].nm[c++]=z;
                if(z!=' '&&!ck[z-'A'])	ck[z-'A']=1;
        	}
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("#%d %s\n",t,a[0].nm);
    }
	return 0;
}
