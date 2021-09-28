#include<cstdio>
int map[20][20], n, x, len, res;
bool check, up;

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t = 1; t <= tc; t++) {
		res = 0;
		scanf("%d %d",&n,&x);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d",&map[i][j]);
		for (int i = 0; i < n; i++) {
			len = 1;
			check = true;
			up = true;
			for (int j = 1; j < n; j++) {
				if (map[i][j] == map[i][j-1])
					len++;
				else if (map[i][j] == map[i][j - 1] - 1) {
					if (up) {
						len = 1;
						up = false;
					}
					else {
						if (len >= x) {
							len = 1;
						}
						else {
							check = false;
							break;
						}
					}
				}
				else if (map[i][j] == map[i][j - 1] + 1) {
					if (up) {
						if (len >= x) {
							len = 1;
						}
						else {
							check = false;
							break;
						}
					}
					else {
						if (len >= x * 2) {
							len = 1;
							up = true;
						}
						else {
							check = false;
							break;
						}
					}
				}
				else {
					check = false;
					break;
				}
				if (j == n - 1) {
					if(!up)
						if (len < x)
							check = false;
				}
			}
			if (check)
				res++;
		}
		for (int i = 0; i < n; i++) {
			len = 1;
			check = true;
			up = true;
			for (int j = 1; j < n; j++) {
				if (map[j][i] == map[j - 1][i])
					len++;
				else if (map[j][i] == map[j - 1][i] - 1) {
					if (up) {
						len = 1;
						up = false;
					}
					else {
						if (len >= x) {
							len = 1;
							up = false;
						}
						else {
							check = false;
							break;
						}
					}
				}
				else if (map[j][i] == map[j-1][i] + 1) {
					if (up) {
						if (len >= x) {
							len = 1;
						}
						else {
							check = false;
							break;
						}
					}
					else {
						if (len >= x * 2) {
							len = 1;
							up = true;
						}
						else {
							check = false;
							break;
						}
					}
				}
				else {
					check = false;
					break;
				}
				if (j == n - 1) {
					if (!up)
						if (len < x)
							check = false;
				}
			}
			if (check)
				res++;
		}
        printf("#%d %d\n",t,res);
	}
	return 0;
}
