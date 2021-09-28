#include<iostream>
#include<algorithm>
using namespace std;
int tc,n,m[100][100],cnt;
typedef struct{int sz,b,c;}a;
a a1[20];

bool cmp(a a1,a a2){
	if(a1.sz==a2.sz)
    	return a1.b<a2.b;
    else	return a1.sz<a2.sz;
}

void sol(int y, int x){
	int d,e;
    d=e=0;
    for(int i=y;i<n;i++){
        if(m[i][x]==0)	break;
        for(int j=x;j<n;j++){
        	if(m[i][j]){
                m[i][j]=0;
                e++;
            }
            else break;
        }
        d++;
    }
    a1[cnt].sz=e;	a1[cnt].b=d;	a1[cnt].c=e/d;
    cnt++;
    return;
}

int main(){
	cin>>tc;
    for(int t=1;t<=tc;t++){
        cin>>n;
        cnt=0;
        for(int i=0;i<20;i++)
            a1[i].sz=a1[i].b=a1[i].c=0;
        for(int i=0;i<n;i++)
        	for(int j=0;j<n;j++)
                cin>>m[i][j];
        for(int i=0;i<n;i++)
        	for(int j=0;j<n;j++)
            	if(m[i][j])	sol(i,j);
        sort(a1,a1+cnt,cmp);
        cout<<'#'<<t<<' '<<cnt<<' ';
        for(int i=0;i<cnt;i++)
            cout<<a1[i].b<<' '<<a1[i].c<<' ';
        cout<<'\n';
    }
}
