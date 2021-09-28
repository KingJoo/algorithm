#include<iostream>
using namespace std;

typedef struct {int x, y, c, p;}BC;	BC ap[8];
typedef struct { int x, y; }H;	H aH, bH;
int res, sum, m, a, A[101], B[101];
enum {NON=0,UP,RIGHT,DOWN,LEFT};
int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};
int aMax1, aMax2, aMax1Idx, bMax1, bMax2, bMax1Idx;

bool dist(BC bc, H h) {
	if (abs(bc.x - h.x) + abs(bc.y - h.y) <= bc.c)	return true;
	else return false;
}

void searchBC(BC (bc)[8], H h, int * Max1, int * Max2, int * Max1Idx) {
	int tmpMax;
	for (int j = 0; j < a; j++) {
		if (dist(bc[j], h)) {
			//최대 없을때
			if (*Max1 == 0) {
				*Max1 = bc[j].p;
				*Max1Idx = j;
			}
			//최대 있을때
			else {
				tmpMax = *Max1;
				//최대와 비교
				if (bc[j].p > tmpMax) {
					*Max1 = bc[j].p;
					*Max1Idx = j;
					*Max2 = *Max2 > tmpMax ? *Max2 : tmpMax;
				}
				//차대와 비교
				else {
					*Max2 = *Max2 > bc[j].p ? *Max2 : bc[j].p;
				}
			}
		}
	}
	return;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//init&input
		res = 0; aH.x = 1; aH.y = 1; bH.x = 10; bH.y = 10;
		cin >> m >> a;
		for (int i = 1; i <= m; i++)
			cin >> A[i];
		for (int i = 1; i <= m; i++)
			cin >> B[i];
		for (int i = 0; i < a; i++)
			cin >> ap[i].x >> ap[i].y >> ap[i].c >> ap[i].p;
		//solve
		for (int i = 0; i <= m; i++) {
			//이동
			aH.x += dx[A[i]];	aH.y += dy[A[i]];
			bH.x += dx[B[i]];	bH.y += dy[B[i]];
			//각 사람마다 접근가능 ap찾아서 최대와 차대 찾기
			aMax1=0, aMax2=0, aMax1Idx=-1, bMax1=0, bMax2=0, bMax1Idx=-1;
			searchBC(ap, aH, &aMax1, &aMax2, &aMax1Idx);
			searchBC(ap, bH, &bMax1, &bMax2, &bMax1Idx);
			//A와B의 최대합
			if (aMax1Idx == bMax1Idx) {
				sum = (aMax1 + bMax2) > (aMax2 + bMax1) ? (aMax1 + bMax2) : (aMax2 + bMax1);
			}
			else	sum = aMax1 + bMax1;
			res += sum;
		}
		//output
		cout << '#' << t << ' ' << res << endl;
	}
	return 0;
}
