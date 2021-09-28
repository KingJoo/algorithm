#include<stdio.h>
#include<string.h>
int tc, l,same;
char s1[11], s2[11];

int main() {
	scanf("%d",&tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%s %s",s1,s2);
		l = strlen(s1);
		same = 1;
		if (l != strlen(s2)) same = 0;
		else {
			for (int i = 0; i < l; i++) {
				if (s1[i] == 'B') {
					if(s2[i] != 'B'){
                        same = 0;
                    	break;
                    }
				}
				else if (s1[i] == 'A' || s1[i] == 'D' || s1[i] == 'O' || s1[i] == 'P' || s1[i] == 'Q' || s1[i] == 'R') {
					if (s2[i] == 'A' || s2[i] == 'D' || s2[i] == 'O' || s2[i] == 'P' || s2[i] == 'Q' || s2[i] == 'R')	continue;
					else {
						same = 0;
						break;
					}
				}
				else {
					if (s2[i] == 'B' || s2[i] == 'A' || s2[i] == 'D' || s2[i] == 'O' || s2[i] == 'P' || s2[i] == 'Q' || s2[i] == 'R') {
						same = 0;
						break;
					}
				}
			}
		}
		printf("#%d ",t);
		if (same)	printf("SAME\n");
		else	printf("DIFF\n");
	}
	return 0;
}
