#include<iostream>
#include<cstring>
#define MAX(a,b) a<b?b:a
using namespace std;

int mCnt, arr[41];

void input() {
	cin >> arr[0] >> arr[1];
	return;
}

void output(int index) {
	cout << '#' << index << ' ';
	for (int i = 2;i <= 40;i++)
		if (mCnt == arr[i])
			cout << i << ' ';
	cout << endl;
}

void reset() {
	memset(arr, 0, sizeof(int) * 41);
	mCnt = 0;
	return;
}

void proc() {
	for (int i = 1;i <= arr[0];i++)
		for (int j = 1;j <= arr[1];j++)
			arr[i + j]++;

	for (int i = 2;i <= arr[0]+arr[1];i++)
		mCnt = MAX(mCnt, arr[i]);

	return;
}

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1;i <= tc;i++) {
		input();
		proc();
		output(i);
		reset();
	}
	return 0;
}
