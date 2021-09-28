#include<iostream>
using namespace std;

int main() {
	int arr[15][15], tc, n, m, sum, max;
	cin >> tc;
	for(int i=1;i<=tc;i++){
		max=0;
        cin >> n >> m;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				cin >> arr[j][k];
		for (int j = 0; j <= n - m; j++)
			for (int k = 0; k <= n - m; k++) {
                sum=0;
				for (int a = 0; a < m; a++)
					for (int b = 0; b < m; b++)
						sum += arr[j + a][k + b];
				if (max < sum)
					max = sum;
        	}
		cout << '#' << i << ' ' << max << endl;
	}
	return 0;
}
