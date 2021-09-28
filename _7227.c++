#include<iostream>
#include<vector>
using namespace std;
int tc, n, a, b;
long long mini, tmp;
vector<pair<int, int>> v;

void dfs(int p, int m, int depth, int sumX, int sumY) {
	if(depth==n){
    	tmp = (long long)sumX * sumX + (long long)sumY * sumY;
		mini = mini < tmp ? mini : tmp;
        return;
    }
    if (p == n / 2)
			dfs(p, m + 1, depth + 1, sumX - v.at(depth).first, sumY - v.at(depth).second);
	else if (m == n / 2)
			dfs(p + 1, m, depth + 1, sumX + v.at(depth).first, sumY + v.at(depth).second);
	else {
		dfs(p + 1, m, depth + 1, sumX + v.at(depth).first, sumY + v.at(depth).second);
		dfs(p, m+1, depth + 1, sumX - v.at(depth).first, sumY - v.at(depth).second);
	}
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		mini = 0x7fffffffffffffff;
		for (int i = 0; i < n;i++){
			cin >> a >> b;
			v.push_back({a,b});
		}
		dfs(0, 0, 0, 0, 0);
		cout << '#' << t << ' ' << mini << '\n';
        v.clear();
	}
	return 0;
}
