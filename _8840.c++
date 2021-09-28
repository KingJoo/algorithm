#include<iostream>
using namespace std;

int main() {
	int tc;
	long long l;
    scanf("%d",&tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%ld",&l);
		l--;
        l >>= 1;
		printf("#%d %ld\n",t,l*l);
	}
	return 0;
}
