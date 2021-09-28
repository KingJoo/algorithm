#include<cstdio>
char st[300],a;
int i,n,top,r;

int main(){
	for(int t=1;t<=10;t++){
    	top=-1;	r=1;
        scanf("%d",&n);
        getchar();
        for(i=1;i<=n;i++){
            st[++top]=getchar();
            if(st[top]==')'){
                if(top==0||st[top-1]!='('){
                    r=0;
                    break;
                }
            	top--;
                top--;
            }
            else if(st[top]=='}'){
                if(top==0||st[top-1]!='{'){
                    r=0;
                    break;
                }
            	top--;
                top--;
            }
            else if(st[top]=='>'){
                if(top==0||st[top-1]!='<'){
                    r=0;
                    break;
                }
            	top--;
                top--;
            }
            else if(st[top]==']'){
                if(top==0||st[top-1]!='['){
                    r=0;
                    break;
                }
            	top--;
                top--;
            }
        }
        while(i<n){
        	getchar();
            i++;
        }
        printf("#%d %d\n",t,r);
    }
	return 0;
}
