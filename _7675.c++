#include<iostream>
using namespace std;
int tc, sCnt, cnt, len;
bool nxt;
string str;

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> sCnt;
		cnt = 0;
		cout << '#' << t << ' ';
		while (sCnt) {
			cin >> str;
			len = str.size()-1;
			nxt = false;
            if ('A' <= str.at(0) && str.at(0) <= 'Z') {
                if(len==0){
                	cnt++;
                    continue;
                }
                for (int i = 1; i < len; i++) {
					if ('a' > str.at(i) || str.at(i) > 'z') {
						nxt = true;
						break;
					}
				}
				if (!nxt) {
					if ('a' <= str.at(len) && str.at(len) <= 'z')
						cnt++;
					else if (str.at(len) == '.' || str.at(len) == '?' || str.at(len) == '!') {
						cnt++;
						sCnt--;
						cout << cnt << ' ';
						cnt = 0;
					}
				}
				else {
					if (str.at(len) == '.' || str.at(len) == '?' || str.at(len) == '!') {
						sCnt--;
						cout << cnt << ' ';
						cnt = 0;
					}
				}
			}
            else{
            	if(str.at(len) == '.' || str.at(len) == '?' || str.at(len) == '!'){
                	sCnt--;
					cout << cnt << ' ';
					cnt = 0;
                }
            }
		}
		cout << '\n';
	}
	return 0;
}
