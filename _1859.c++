#include<iostream>
using namespace std;
short arr[1000000];

int main() {
	int tc,n,max;
	long long int sum;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n;
		sum = 0;
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		max=arr[n-1];
        for(int j=n-2;j>=0;j--){
        	if(max>=arr[j])
                sum+=max-arr[j];
            else
                max=arr[j];
        }
		cout << '#' << i << ' ' << sum << '\n';
	}
	return 0;
}
