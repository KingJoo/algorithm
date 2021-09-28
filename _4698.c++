#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int tc,d,a,b,sz,tmp,r;
bool ck[1000001];
vector<int> v;

int bs(int s,int e){
	if(s>e)	return s;
    else{
        int mid=(s+e)/2;
    	if(v.at(mid)==a)	return mid;
        else if(v.at(mid)<a)	bs(mid+1,e);
        else	bs(s,mid-1);
    }
}

int main(){
	scanf("%d",&tc);
    for(int i=2;i<1000001;i++){
    	if(!ck[i]){
        	v.push_back(i);
            for(int j=i+i;j<1000001;j+=i)
                ck[j]=true;
        }
    }
    sz=v.size();
    for(int t=1; t<=tc;t++){
    	scanf("%d %d %d",&d,&a,&b);
        r=0;
        for(int i=bs(0,sz-1);i<sz;i++){
        	tmp=v.at(i);
            if(tmp>b)	break;
            while(tmp){
            	if(tmp%10==d){
                	r++;
                    break;
                }
                tmp/=10;
            }
        }
    	printf("#%d %d\n",t,r);
    }
	return 0;
}
