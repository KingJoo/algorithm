#include<stdio.h>
int tc,n,t,p,d,ns[2000],nn[2000],pS[2000],a,i,j,nnp,nsp;
char nt[2000][2000];

int main(){
    scanf("%d",&tc);
    for(a=1;a<=tc;a++){
		scanf("%d %d %d",&n,&t,&p);
        while(getchar()!='\n');
        d=1;	for(i=0;i<n;i++)	nn[i]=ns[i]=0;	for(i=0;i<t;i++)	pS[i]=0; p--;
        for(i=0;i<n;i++){
			for(j=0;j<t;j++){
				nt[i][j]=getchar();
                getchar();
				if(nt[i][j]=='1')	nn[i]++;
                else	pS[j]++;
			}
        }
        nnp=nn[p];

        for(i=0;i<n;i++)
			for(j=0;j<t;j++)
                if(nt[i][j]=='1')	ns[i]+=pS[j];
        nsp=ns[p];

		for(i=0;i<n;i++){
			if(ns[i]>nsp)	d++;
			else if(ns[i]==nsp){
				if(nn[i]>nnp)	d++;
				else if(nn[i]==nnp)
					if(i<p)	d++;
			}
		}
		printf("#%d %d %d\n",a,nsp,d);
	}
	return 0;
}
