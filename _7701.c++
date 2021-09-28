#include<cstdio>
#include<cstdlib>
#include<cstring>
int tc,n;
char name[20000][51],tmp[51];

int cmp(const void * a,const void * b){
	if(strlen((char*)a)!=strlen((char*)b))	return strlen((char*)a)>strlen((char*)b);
    else return strcmp((char *)a,(char *)b);
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",name[i]);
        qsort(name,n,sizeof(name[0]),cmp);
        printf("#%d\n",t);
        strcpy(tmp,name[0]);
        for(int i=0;i<n;i++){
            if(i&&strcmp(tmp,name[i])==0)	continue;
            strcpy(tmp,name[i]);
            printf("%s\n",name[i]);
        }
    }
	return 0;
}
