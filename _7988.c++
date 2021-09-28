#include<cstdio>
#include<cstring>
char n[100][2][51],s[51];
int i,j,tc,k,v[100][2],c,p,a,st[200][2],z,x,d;
bool r,b;

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d",&k);
        r=1; c=0; a=-1;	d=k<<1;
        for(i=0;i<k;i++){
            scanf("%s%s",n[i][0],n[i][1]);
            v[i][0]=v[i][1]=0;
        }
        while(c!=d&&r){
            if(a==-1){
                b=0;
            	for(i=0;i<k&&!b;i++)
                	for(j=0;j<2&&!b;j++)
                		if(v[i][j]==0){
                    		c++;
                    		if(v[i][(j+1)%2]==1)	v[i][j]=p=2;
                            else{
                                v[i][j]=p=1;
                                if(v[i][(j+1)%2]==0){st[++a][0]=i;	st[a][1]=(j+1)%2;}
                            }
                    		strcpy(s,n[i][j]);
                       		b=1;
                		}
            }
            else{
                z=st[a][0];
                x=st[a--][1];
               	if(v[z][x]!=0)	continue;
                strcpy(s,n[z][x]);
                if(v[z][(x+1)%2]==1)	p=2;
                else p=1;
            }
            for(i=0;i<k&&r;i++)
                for(j=0;j<2&&r;j++)
                    if(strcmp(n[i][j],s)==0){
                   		if(v[i][j]==0){
                            if(v[i][(j+1)%2]==p)	r=0;
                            else{
                            	v[i][j]=p;
                                c++;
                                if(v[i][(j+1)%2]==0){st[++a][0]=i; st[a][1]=(j+1)%2;}
                            }
                        }
                        else if(v[i][j]!=p)	r=0;
                   	}
        }
    	printf("#%d ",t);
        if(r)	printf("Yes\n");
        else	printf("No\n");
    }
	return 0;
}
