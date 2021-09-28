#include <cstdio>
#include <cstring>
int tc,n,m[20][20],c,k,l;
char s[21];
bool o;
enum{R=1<<4,D=1<<3,LD=1<<2,RD=1<<1};//우,하,좌하,우하

int main(){
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	scanf("%d",&n);
        for(int i=0;i<n;i++){
        	scanf("%s",s);
            for(int j=0;j<n;j++)
            	if(s[j]=='o')
                    m[i][j]++;
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
            	if(m[i][j]){
                    //가로
                    if((R&m[i][j])==0){
                        c = 0;
                        for(k=j;k<n;k++){
                        	if(m[i][k]==0)	break;
                            c++;
                            m[i][k]|=R;
                    	}
                        if(c>=5){
                        	o=true;
                            break;
                        }
                    }
                    //세로
                    if((D&m[i][j])==0){
                        c = 0;
                        for(k=i;k<n;k++){
                        	if(m[k][j]==0)	break;
                            c++;
                            m[k][j]|=D;
                        }
                        if(c>=5){
                        	o=true;
                            break;
                        }
                    }
                    //좌하
                    if((LD&m[i][j])==0){
                        c = 0;
                        k = i;
                        l = j;
                        while(true){
                       		if(k==n||l<0)	break;
                            if(m[k][l]==0)	break;
                            c++;
                            m[k++][l--]|=LD;
                        }
                        if(c>=5){
                        	o=true;
                            break;
                        }
                    }
                    //우하
                    if((RD&m[i][j])==0){
                        c = 0;
                        k = i;
                        l = j;
                        while(true){
                            if(k==n||l==n)	break;
                            if(m[k][l]==0)	break;
                            c++;
                            m[k++][l++]|=RD;
                        }
                        if(c>=5){
                        	o=true;
                            break;
                        }
                    }
                }
            }
            if(o)	break;
        }
        if(o)	printf("#%d YES\n",t);
        else	printf("#%d NO\n",t);
        memset(m,0,sizeof(m));
        o=false;
    }
    return 0;
}
