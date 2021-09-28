#include<iostream>
#include<algorithm>
using namespace std;
int tc,n,c[100000],s;
bool cmp(int a,int b){return a>b;}
int main(){
	cin>>tc;
    for(int t=1;t<=tc;t++){
    	s=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>c[i];
        sort(c,c+n,cmp);
        for(int i=0;i<n-3;i=i+3)
        	s+=(c[i]+c[i+1]);
        if(n%3==1)	s+=c[n-1];
        else	if(n%3==2)	s+=(c[n-2]+c[n-1]);
        else	s+=(c[n-3]+c[n-2]);
        cout<<'#'<<t<<' '<<s<<'\n';
    }
	return 0;
}
