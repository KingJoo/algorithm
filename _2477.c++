#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define N_MAX 10
#define M_MAX 10
#define K_MAX 1001

//input val
int ai[N_MAX];
int bj[M_MAX];
int tk[K_MAX];
int N, M, K, A, B;

//proc() val
int NN[N_MAX];
int ai_lock[N_MAX];
int MM[M_MAX];
int bj_lock[M_MAX];

queue<int> q1, q2;
vector<int> v1, v2;

void input() {
	int i = 0;
	cin >> N >> M >> K >> A >> B;
	for (i = 1;i <= N;i++)
		cin >> ai[i];
	for (i = 1;i <= M;i++)
		cin >> bj[i];
	for (i = 1;i <= K;i++)
		cin >> tk[i];
	return;
}

int NisEmpty() {
	for (int i = 1;i <= N;i++)
		if (ai_lock[i] == 0)
			return i;
	return 0;
}

int MisEmpty() {
	for (int i = 1;i <= M;i++)
		if (bj_lock[i] == 0)
			return i;
	return 0;
}

bool allEmpty(int arr[], int num) {
	for (int i = 1;i <= num;i++)
		if (arr[i] != 0)
			return false;
	return true;
}

int proc() {
	int res = 0;
	int k = 1;
	int tick = 0;
	int idx = 0;
	while (true) {
        if (tick > tk[K])
			if (q1.empty())
				if (allEmpty(ai_lock, N)&&allEmpty(NN, N))
					if (q2.empty())
						if (allEmpty(bj_lock, M)&& allEmpty(MM, M))
							break;
		for (int i = 1;i <= M;i++)
			if (bj_lock[i] == 0)
				if (MM[i] != 0)
					MM[i] = 0;
		for (int i = 1;i <= N;i++)
			if (ai_lock[i] == 0)
				if (NN[i] != 0) {
					q2.push(NN[i]);
					NN[i] = 0;
				}
		if (tick <= tk[K]) {
			while (true) {
				if (tick == tk[k]) {
					q1.push(k);
					k++;
					if (k > K)
						break;
				}
				else break;
			}
		}
		while (q1.size()) {
			idx = NisEmpty();
			if (idx != 0) {
				NN[idx] = q1.front();
				q1.pop();
				ai_lock[idx] = ai[idx];
				if (idx == A)
					v1.push_back(NN[idx]);
			}
			else break;
		}
		while (q2.size()) {
			idx = MisEmpty();
			if (idx != 0) {
				MM[idx] = q2.front();
				q2.pop();
				bj_lock[idx] = bj[idx];
				if (idx == B)
					v2.push_back(MM[idx]);
			}
			else break;
		}
		tick++;
		for (int i = 1;i <= N;i++)
			if(ai_lock[i]!=0)
				ai_lock[i]--;
		for (int i = 1;i <= M;i++)
			if(bj_lock[i]!=0)
				bj_lock[i]--;
	}
	for (int i = 0;i < v1.size();i++) {
		int tmp1 = v1.at(i);
		for (int j = 0;j < v2.size();j++) {
			if (tmp1 == v2.at(j)) {
				res += tmp1;
				break;
			}
		}
	}
	if (res == 0)
		res = -1;
	while (v1.size()) {
		v1.pop_back();
	}
	while (v2.size()) {
		v2.pop_back();
	}

	return res;
}

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		input();
		cout << '#' << i << ' ' << proc() << '\n';
	}
	return 0;
}
