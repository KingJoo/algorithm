#include<cstdio>
bool ck[1000001];
int main(){
    for(int i=2;i<1000001;i++){
    	if(!ck[i]){
            printf("%d ",i);
            for(int j=i+i;j<1000001;j+=i)
                if(!ck[j])	ck[j]=true;
        }
    }
    return 0;
}
