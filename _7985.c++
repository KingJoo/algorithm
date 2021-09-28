#include<iostream>
#include<cstring>
using namespace std;
int tc, a[1023], k, len, pre, half;
bool chk[1023];

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> k;
		len = half = (1 << k) - 1;
        memset(chk,0,sizeof(chk));
		for (int i = 0; i < len; i++)
			cin >> a[i];
        cout << '#' << t << ' ';
		for(int i=0;i<k;i++){
        	pre=half;
            half=pre>>1;
            for(int j=half;j<len;j=j+pre-half){
            	if(!chk[j]){
                	cout<< a[j] << ' ';
					chk[j]=true;
                }
            }
         	cout << '\n';
        }
	}
	return 0;
}
