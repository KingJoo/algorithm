#include<cstdio>
int tc,n,m[20][20],e,s,T[20];
char S[6];

int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d %s",&n,S);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            	scanf("%d",&m[i][j]);
        if(S[0]=='u')
            for(int j=0;j<n;j++){
                e=s=0;
                for(int i=0;i<n;i++)
                    if(m[i][j])	T[e++]=m[i][j];
            	for(int k=0;k<e;k++)
                	if(k<e-1&&T[k]==T[k+1])	m[s++][j]=T[k++]<<1;
            		else	m[s++][j]=T[k];
                for(;s<n;s++)
                    m[s][j]=0;
            }
        else if(S[0]=='d')
        	for(int j=0;j<n;j++){
                e=s=n-1;
                for(int i=n-1;i>=0;i--)
                    if(m[i][j])	T[e--]=m[i][j];
            	for(int k=n-1;k>e;k--)
                	if(k>e+1&&T[k]==T[k-1])	m[s--][j]=T[k--]<<1;
            		else	m[s--][j]=T[k];
                for(;s>=0;s--)
                    m[s][j]=0;
            }
        else if(S[0]=='l')
        	for(int i=0;i<n;i++){
                e=s=0;
                for(int j=0;j<n;j++)
                    if(m[i][j])	T[e++]=m[i][j];
            	for(int k=0;k<e;k++)
                	if(k<e-1&&T[k]==T[k+1])	m[i][s++]=T[k++]<<1;
            		else	m[i][s++]=T[k];
                for(;s<n;s++)
                    m[i][s]=0;
            }
        else
        	for(int i=0;i<n;i++){
                e=s=n-1;
                for(int j=n-1;j>=0;j--)
                    if(m[i][j])	T[e--]=m[i][j];
            	for(int k=n-1;k>e;k--)
                	if(k>e+1&&T[k]==T[k-1])	m[i][s--]=T[k--]<<1;
            		else	m[i][s--]=T[k];
                for(;s>=0;s--)
                    m[i][s]=0;
            }
        printf("#%d\n",t);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d ",m[i][j]);
            putchar('\n');
        }
    }
	return 0;
}
