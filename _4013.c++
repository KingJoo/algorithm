#include<iostream>
#include<deque>
#define endl '\n'
using namespace std;
deque<int> dq[4];
int k, tmp, res;
int n, way;

void R(deque<int> * DQ) {
	(*DQ).push_front((*DQ).back());
	(*DQ).pop_back();
	return;
}

void _R(deque<int> * DQ) {
	(*DQ).push_back((*DQ).front());
	(*DQ).pop_front();
	return;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//init
		for (int i = 0; i < 4; i++)
			dq[i].clear();
		//input
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> tmp;
				dq[i].push_back(tmp);
			}
		}
		//정보 input & proc
		for (int i = 0; i < k; i++) {
			cin >> n >> way;
			if (n == 1) {
				if (way == 1) {
					R(dq);
					if (dq[0].at(3) != dq[1].at(6)) {
						_R(dq+1);
						if (dq[1].at(1) != dq[2].at(6)) {
							R(dq+2);
							if (dq[2].at(3) != dq[3].at(6))
								_R(dq+3);
						}
					}
				}
				else {
					_R(dq);
					if (dq[0].at(1) != dq[1].at(6)) {
						R(dq+1);
						if (dq[1].at(3) != dq[2].at(6)) {
							_R(dq+2);
							if (dq[2].at(1) != dq[3].at(6))
								R(dq+3);
						}
					}
				}
			}
			else if (n == 2) {
				if (way == 1) {
					R(dq+1);
					if (dq[1].at(7) != dq[0].at(2))
						_R(dq);
					if (dq[1].at(3) != dq[2].at(6)) {
						_R(dq+2);
						if (dq[2].at(1) != dq[3].at(6))
							R(dq+3);
					}
				}
				else {
					_R(dq+1);
					if (dq[1].at(5) != dq[0].at(2))
						R(dq);
					if (dq[1].at(1) != dq[2].at(6)) {
						R(dq+2);
						if (dq[2].at(3) != dq[3].at(6))
							_R(dq+3);
					}
				}
			}
			else if (n == 3) {
				if (way == 1) {
					R(dq+2);
					if (dq[2].at(3) != dq[3].at(6))
						_R(dq+3);
					if (dq[2].at(7) != dq[1].at(2)) {
						_R(dq+1);
						if (dq[1].at(5) != dq[0].at(2))
							R(dq);
					}
				}
				else {
					_R(dq+2);
					if (dq[2].at(1) != dq[3].at(6))
						R(dq+3);
					if (dq[2].at(5) != dq[1].at(2)) {
						R(dq+1);
						if (dq[1].at(7) != dq[0].at(2))
							_R(dq);
					}
				}
			}
			else {
				if (way == 1) {
					R(dq+3);
					if (dq[3].at(7) != dq[2].at(2)) {
						_R(dq+2);
						if (dq[2].at(5) != dq[1].at(2)) {
							R(dq+1);
							if (dq[1].at(7) != dq[0].at(2))
								_R(dq);
						}
					}
				}
				else {
					_R(dq+3);
					if (dq[3].at(5) != dq[2].at(2)) {
						R(dq+2);
						if (dq[2].at(7) != dq[1].at(2)) {
							_R(dq+1);
							if (dq[1].at(5) != dq[0].at(2))
								R(dq);
						}
					}
				}
			}
		}
		res = dq[0].front() * 1 + dq[1].front() * 2 + dq[2].front() * 4 + dq[3].front() * 8;
		//output
		cout << '#' << t << ' ' << res << endl;
	}
	return 0;
}
