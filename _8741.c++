#include<iostream>
using namespace std;

int main() {
	int tc;
	bool prt;
	cin >> tc;
	char ch;
	scanf("%c", &ch);
	for (int t = 1; t <= tc; t++) {
		prt = false;
		printf("#%d ", t);
		while (true) {
			scanf("%c",&ch);
			if (!prt) {
				ch -= 'a';
				ch += 'A';
				printf("%c", ch);
				prt = true;
			}
			if (ch == ' ')
				prt = false;
			else if (ch == '\n')
				break;
		}
		printf("\n");
	}
	return 0;
}
