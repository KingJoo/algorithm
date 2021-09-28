#include<iostream>
using namespace std;
int tc,n,b,m,s[20];

void comb(int idx,int sum){
	if(m==b)	return;
    if(idx==n){
    	if(sum<b)	return;
        else{
            m=m<sum?m:sum;
            return;
        }
    }
    comb(idx+1,sum+s[idx]);
    comb(idx+1,sum);
}

int main(){
	cin>>tc;
    for(int t=1;t<=tc;t++){
        cin>>n>>b;
        m=0x7fffffff;
        for(int i=0;i<n;i++)
            cin>>s[i];
        comb(0,0);
        cout<<'#'<<t<<' '<<m-b<<'\n';
    }
	return 0;
}
