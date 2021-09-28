#include<cstdio>
#include<vector>
using namespace std;
int tc, t, sz, n, tp, cnt;
bool ck[1000];
vector<int> v;

bool bs(int s, int e, int search) {
	if (s > e)	return false;
    else {
		int mid = (s + e) / 2;
		int val = v.at(mid);
		if (val == search)	return true;
		else if(val < search)	bs(mid+1, e, search);
		else	bs(s, mid-1, search);
	}
}

int main() {
	scanf("%d", &tc);
	t = 2;
	while (t < 1000) {
		if (!ck[t]) {
			ck[t] = true;
			v.push_back(t);
			for (int i = t + t; i < 1000; i += t)
				ck[i] = true;
		}
		t++;
	}
	sz = v.size();
	for (t = 1; t <= tc; t++) {
		cnt = 0;
		scanf("%d", &n);
		for(int i=0;i<sz;i++){
            for(int j=i;j<sz;j++){
                tp=n-v.at(i)-v.at(j);
                if(tp<=0)	break;
                if(bs(j,sz-1,tp))	cnt++;
            }
    	}
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}
