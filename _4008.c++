#include<iostream>
using namespace std;
int number[12], n, MAX, MIN;
int opNum[4];//op 개수

void dfs(int num, int idx) {
    if (idx == n) {
    	MAX = num > MAX ? num : MAX;
		MIN = num < MIN ? num : MIN;
	}
    else{
    	if(opNum[0]>0){
            opNum[0]--;
            dfs(num+number[idx],idx+1);
            opNum[0]++;
        }
        if(opNum[1]>0){
            opNum[1]--;
            dfs(num-number[idx],idx+1);
            opNum[1]++;
        }
        if(opNum[2]>0){
            opNum[2]--;
            dfs(num*number[idx],idx+1);
            opNum[2]++;
        }
        if(opNum[3]>0){
            opNum[3]--;
            dfs(num/number[idx],idx+1);
            opNum[3]++;
        }
    }
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//init
		MAX = 0x80000000;
		MIN = 0x7fffffff;
        //input
		cin >> n;
		for (int i = 0; i < 4; i++)
			cin >> opNum[i];
		for (int i = 0; i < n; i++)
			cin >> number[i];
		//solve
		dfs(number[0], 1);
		//output
		cout << '#' << t << ' ' << MAX-MIN << endl;
	}
	return 0;
}
