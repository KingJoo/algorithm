#include<cstdio>
using namespace std;
int tc, n, back, front, m, tp, mx, nn[1000];
bool nxt;

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d",&nn[i]);
		mx = -1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				nxt = false;
				m = nn[i] * nn[j];
				tp = m;
				back = 9;
				while (tp!=0) {
					front = tp % 10;
					tp /= 10;
					if (front > back) {
						nxt = true;
						break;
					}
					else	back = front;
				}
				if (!nxt)	mx = mx > m ? mx : m;
			}
		}
		printf("#%d %d\n", t, mx);
	}
	return 0;
}
