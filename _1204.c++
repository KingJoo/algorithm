#include<cstdio>
#include<cstring>

int main() {
	int t, tc, sc, score[101], mxCnt;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		memset(score,0,sizeof(score));
    	scanf("%d", &tc);
        for(int j=0;j<1000;j++){
			scanf("%d", &sc);
			score[sc]++;
		}
		mxCnt = 0;
        for (int j = 100; j >= 0; j--) {
			if (score[j] > mxCnt) {
				mxCnt = score[j];
				sc = j;
			}
		}
		printf("#%d %d\n", tc, sc);
	}
	return 0;
}
