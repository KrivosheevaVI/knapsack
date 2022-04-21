#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("ks_1000_0", "r", stdin);
    int n, Size;
    cin >> n >> Size;
    vector<int> value(n);
    vector<int> weight(n);
    
    for (int i = 0; i < n; i++) {
	cin >> value[i] >> weight[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (Size+1));
    vector<vector<int>> parent(n+1, vector<int>(Size+1));
    dp[0][0] = 0;

    for (int i = 1; i <= Size; i++) {
	dp[0][i] = -1;
    }

    for (int i = 1; i <= n; i++) {
	for (int j = 0; j <= Size; j++) {
	    int p1, p2;
	    p1 = p2 = -1;
	    p2 = dp[i-1][j];
	    if (j - weight[i - 1] >= 0) {
		p1 = dp[i - 1][j - weight[i - 1]] + value[i-1];
		
	    }
	    if (p1 >= p2) {
		dp[i][j] = p1;
		parent[i][j] = 1; //взяли предмет

	    }
	    else {
		dp[i][j] = p2;
		parent[i][j] = 0; //не взяли предмет
	    }
	}
    }
    int id = 0;
    for (int i = 1; i <= Size; i++) {
	if (dp[n][i] > dp[n][id]) {
	    id = i;
	}
    }
    cout << dp[n][id] <<" "<< id << endl;

    vector<int> answer(n, 0);
    int j = id;
    int i = n;

    while (i > 0) {
	if (parent[i][j] == 1) {
	    answer[i - 1] = 1;
	    i--;
	    j = j - weight[i];
	}
	else {
	    i--;
	}
    }
    for (int k = 0; k < n; k++) {
	cout << answer[k] << ' ';
    }
}