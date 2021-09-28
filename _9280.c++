#include<cstdio>
int tc,n,m,s,nn[100],mm[2001],chk[100];
int q[2000],qs,qe;

int check(){
	for(int i=0;i<n;i++)
        if(chk[i]==0)	return i;
    return -1;
}

void in(int a){
	int loc=check();
    if(loc==-1)	q[qe++]=a;
    else{
        if(qs==qe){
        	chk[loc]=a;
        	s+=mm[a]*nn[loc];
        }
        else{
        	chk[loc]=q[qs++];
            s+=mm[chk[loc]]*nn[loc];
            q[qe++]=a;
        }
    }
    return;
}

void out(int a){
    int i;
    for(i=0;i<n;i++){
        if(chk[i]==a){
            chk[i]=0;
            break;
        }
    }
    if(qs!=qe){
    	chk[i]=q[qs++];
        s+=mm[chk[i]]*nn[i];
    }
    else chk[i]=0;
    return;
}

int main(){
	scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
    	s=qs=qe=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",nn+i);
        for(int i=1;i<=m;i++)
            scanf("%d",mm+i);

        if(n==1){
            for(int i=0;i<2*m;i++)	scanf("%d",mm);
            for(int i=1;i<=m;i++)	s+=mm[i];
            s*=nn[0];
        }
        else{
        	for(int i=0;i<2*m;i++){
            	scanf("%d",mm);
                if(mm[0]<0)	out(-mm[0]);
                else	in(mm[0]);
            }
        }
        printf("#%d %d\n",t,s);
    }
    return 0;
}
